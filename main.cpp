#include <iostream>
#include <string>
#include "Clock.h"
using namespace std;

int main() {
    int hours, min, sec;
    bool is24HourFormat, isAM;
    string yesOrNo;

    cout << endl << "Default Clock:" << endl;
    Clock defaultClock;
    defaultClock.show();
    cout << "One Second Passing..." << endl;
    defaultClock.tick();
    defaultClock.show();
    cout << "Switching Time Format..." << endl;
    defaultClock.toggleFormat();
    defaultClock.show();

    cout << endl << "Clock Implementation with 3 Arguments: " << endl;
    cout << "Please enter a positive integer (0 - 23 inclusive) for the hours: ";
    cin >> hours;

    cout << "Please enter a positive integer (0 - 59 inclusive) for the minutes: ";
    cin >> min;

    cout << "Please enter a positive integer (0 - 59 inclusive) for the seconds: ";
    cin >> sec;

    Clock secondClock(hours, min, sec);

    secondClock.show();
    cout << "One Second Passing..." << endl;
    secondClock.tick();
    secondClock.show();
    cout << "Switching Time Format..." << endl;
    secondClock.toggleFormat();
    secondClock.show();

    cout << endl << "Clock Implementation with 5 Arguments: " << endl;

    do {
        cout << "Will you be using the 24-Hour Format? (y/n): ";
        cin >> yesOrNo;
    } while (yesOrNo != "y" && yesOrNo != "n");

    if (yesOrNo == "y") {
        is24HourFormat = true;
    } else {
        is24HourFormat = false;
    }

    do {
        cout << "Will your time be in the AM? (y/n): ";
        cin >> yesOrNo;
    } while (yesOrNo != "y" && yesOrNo != "n");

    if (yesOrNo == "y") {
        isAM = true;
    } else {
        isAM = false;
    }

    if (is24HourFormat) {
        cout << "Please enter a positive integer (0 - 23 inclusive) for the hours: ";
        cin >> hours;
    } else {
        cout << "Please enter a positive integer (1 - 12 inclusive) for the hours: ";
        cin >> hours;
    }

    cout << "Please enter a positive integer (0 - 59 inclusive) for the minutes: ";
    cin >> min;

    cout << "Please enter a positive integer (0 - 59 inclusive) for the seconds: ";
    cin >> sec;

    Clock thirdClock(hours, min, sec, is24HourFormat, isAM);

    thirdClock.show();
    cout << "One Second Passing..." << endl;
    thirdClock.tick();
    thirdClock.show();
    cout << "Switching Time Format..." << endl;
    thirdClock.toggleFormat();
    thirdClock.show();

    return 0;
}