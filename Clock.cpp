#include <iostream>
#include <iomanip>
#include "Clock.h"
using namespace std;

Clock::Clock(){
    hours = 0;
    minutes = 0;
    seconds = 0;
    is24Hour = true;
    isAM = true;
}

Clock::Clock(int h, int m, int s){
    is24Hour = true;
    isAM = true;
    if (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
        hours = h;
        minutes = m;
        seconds = s;
    } else {
        cout << "Error: Invalid Input. Time set to 00:00:00" << endl;
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
}

Clock::Clock(int h, int m, int s, bool format, bool am){
    is24Hour = format;
    isAM = am;
    if (is24Hour) {
        if (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
            hours = h;
            minutes = m;
            seconds = s;
        } else {
            cout << "Error: Invalid Input. Time set to 00:00:00" << endl;
            hours = 0;
            minutes = 0;
            seconds = 0;
        }
    } else {
        if (h >= 1 && h <= 12 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
            hours = h;
            minutes = m;
            seconds = s;
        } else {
            cout << "Error: Invalid Input. Time set to 00:00:00" << endl;
            hours = 0;
            minutes = 0;
            seconds = 0;
        }
    }
}

void Clock::toggleFormat() {
    if (is24Hour) {
        if (hours >= 0 && hours <= 11) {
            if (hours == 0) {
                hours = 12;
            }
            isAM = true;
        } else {
            if (hours == 12) {
                hours = 12;
            } else {
                hours = hours - 12;
            }
            isAM = false;
        }
    } else {
        if (isAM && hours == 12) {
            hours = 0;
        } else if (!isAM && hours == 12) {
            hours = 12;
        } else if (!isAM) {
            hours = hours + 12;
        }
    }
    is24Hour = !is24Hour;
}

void Clock::show() {
    cout << "The Current Time is: ";
    if (is24Hour) {
        cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << endl;
    } else {
        if (isAM) {
            cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " AM" << endl;
        } else {
            cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " PM " << endl;
        }
    }
}

void Clock::tick() {
    seconds++;

    if (seconds == 60) {
        seconds = 0;
        minutes++;

        if (minutes == 60) {
            minutes = 0;
            hours++;

            if (hours == 24) {
                hours = 0;
            }
        }
    }
}