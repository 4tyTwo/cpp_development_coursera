#include <string>

using namespace std;

struct Specialization {
    string value;
    explicit Specialization(string v) 
    {
        value = v;
    }
};

struct Course {
    string value;
    explicit Course(string v) 
    {
        value = v;
    }
};

struct Week {
    string value;
    explicit Week(string v) 
    {
        value = v;
    }
};

struct LectureTitle {
  string specialization;
  string course;
  string week;
  LectureTitle(const Specialization& spec, const Course& course, const Week& week) 
  {
      specialization = spec.value;
      this->course = course.value;
      this->week = week.value;
  }
};
