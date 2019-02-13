#include <iostream>

using namespace std;

class Time {
    int hours;
    int minutes;
    int seconds;
public :
    Time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    Time(int hrs, int mins, int secs) {
        hours = hrs;
        minutes = mins;
        seconds = secs;
    }

    void display() {
        cout << hours << " : " << minutes << " : " << seconds << endl;
    }

    void add(Time t1, Time t2) {
        seconds = t1.seconds + t2.seconds;
        minutes = seconds / 60;
        seconds = seconds % 60;
        minutes += t1.minutes + t2.minutes;
        hours = minutes / 60;
        minutes = minutes % 60;
        hours += t1.hours + t2.hours;
        hours = hours % 24;
    }
};

int main() {
    int hrs, mins, secs;
    cin >> hrs >> mins >> secs;
    Time t1(hrs, mins, secs);
    cin >> hrs >> mins >> secs;
    Time t2(hrs, mins, secs);
    Time t3;
    t3.add(t1,t2);
    t3.display();
    return 0;
}