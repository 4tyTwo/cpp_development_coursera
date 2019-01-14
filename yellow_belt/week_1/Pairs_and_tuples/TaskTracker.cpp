#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus
{
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks
{
public:
    const TasksInfo& GetPersonTasksInfo(const string& person) const
    {
        return team.at(person);
    }
  
    void AddNewTask(const string& person)
    {
        ++team[person][TaskStatus::NEW];
    }
  
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
        const string& person, int task_count)
    {
        TasksInfo new_task_info;
        TasksInfo touched, untouched;
        for (const auto& i : {TaskStatus::NEW, TaskStatus::IN_PROGRESS, TaskStatus::TESTING})
        {
            int to_perform = team[person][i];
            if (to_perform > task_count)
                to_perform = task_count;
            auto next = static_cast<TaskStatus>(static_cast<int>(i) + 1);
            touched[next] = to_perform;
            untouched[i] = team.at(person)[i] - to_perform;
            task_count -= to_perform;
        }
        
        new_task_info[TaskStatus::DONE] = team[person][TaskStatus::DONE];
        for (const auto& i : {TaskStatus::NEW, TaskStatus::IN_PROGRESS, TaskStatus::TESTING, TaskStatus::DONE})
            new_task_info[i] += touched[i] + untouched[i];
        
        clean_task_info(new_task_info);
        clean_task_info(touched);
        clean_task_info(untouched);
        team[person] = new_task_info;
        return tie(touched, untouched);
    }

private:

    void clean_task_info(TasksInfo& m)
    {
        for(auto it = begin(m);it != end(m);)
             if (it->second == 0)
                m.erase(it++);
            else
                ++it; 
    }

    map<string, TasksInfo> team;
};

void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() 
{
    TeamTasks tasks;
    //TasksInfo touched, untouched;
   // auto res = tie(touched, untouched);
    for (int i = 0; i < 5; ++i)
        tasks.AddNewTask("Alice");
    tasks.PerformPersonTasks( "Alice", 5);
    tasks.PerformPersonTasks( "Alice", 5);
    tasks.PerformPersonTasks( "Alice", 1);
    for (int i = 0; i < 5; ++i)
        tasks.AddNewTask("Alice");
    tasks.PerformPersonTasks( "Alice", 2);
    auto res2 = tasks.GetPersonTasksInfo("Alice");
    for (auto i : res2)
        cout << static_cast<int>(i.first) << ": " << i.second << endl;  
    tasks.PerformPersonTasks( "Alice", 4);
    tasks.GetPersonTasksInfo("Alice");

    return 0;
}
