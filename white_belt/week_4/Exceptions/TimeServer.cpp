#include <iostream>
#include <exception>
#include <string>
#include <system_error>
#include <time.h>

using namespace std;

string AskTimeServer() {
    srand(time(NULL));
    int rnd = rand()%3;
    if (rnd == 0)
        throw system_error(error_code(42, system_category()), "Network error");
    if (rnd == 1)
        throw runtime_error("Something went wrong");
    return "16:21:58";
}

class TimeServer {
public:
    string GetCurrentTime()
    {
        try {
            LastFetchedTime = AskTimeServer();
        }
        catch (system_error& e) {
            return LastFetchedTime;
        }
        catch (exception& e) {
            throw;
        }
        return LastFetchedTime;
    }

private:
    string LastFetchedTime = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
