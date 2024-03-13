#include <iostream>
#include <string>
#include "Clock.h"
using namespace std;

int main() {
    int hours, min, sec;
    bool is24HourFormat;
    string yesOrNo;
    Clock myClock(13, 45, 10, true);

    myClock.show();
    cout << endl << "One Second Passing..." << endl;
    myClock.tick();
    myClock.show();
    cout << endl;

    do {
        cout << "Will you be using the 24-Hour Format? (y/n): ";
        cin >> yesOrNo;
    } while (yesOrNo != "y" && yesOrNo != "n");

    if (yesOrNo == "y") {
        is24HourFormat = true;
    } else {
        is24HourFormat = false;
    }

    if (is24HourFormat) {
        do {
            cout << "Please enter a positive integer (0 - 24 inclusive) for the hours: ";
            cin >> hours;
        } while (hours < 0 || hours > 24);
    } else {
        do {
            cout << "Please enter a positive integer (0 - 12 inclusive) for the hours: ";
            cin >> hours;
        } while (hours < 0 || hours > 12);
    }

    do {
        cout << "Please enter a positive integer (0 - 60 inclusive) for the minutes: ";
        cin >> min;
    } while (min < 0 || min > 60);

    do {
        cout << "Please enter a positive integer (0 - 60 inclusive) for the seconds: ";
        cin >> sec;
    } while (sec < 0 || sec > 60);

    Clock myClock2(hours, min, sec, is24HourFormat);

    myClock2.show();
    cout << endl << "One Second Passing..." << endl;
    myClock2.tick();
    myClock2.show();

    return 0;
}
