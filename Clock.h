#ifndef CLOCK_H
#define CLOCK_H
#include <iostream>

using namespace std;

class Clock{
private:
    int hours;
    int minutes;
    int seconds;
    bool is24Hour;


public:
    Clock(){
        hours = 0;
        minutes = 0;
        seconds = 0;
        is24Hour = true;
    }

    //MAYBE WANT TO INCLUDE A WAY TO MAKE SURE USERS INPUT A CORRECT VALUE
    Clock(int h, int m, int s, bool i){
        hours = h;
        minutes = m;
        seconds = s;
        is24Hour = i;
    }

    void toggleFormat() {
        is24Hour = !is24Hour;
    }

    //MAYBE WANT TO ADD IN SOMETHING THAT PUTS A 0 IN FRONT OF THE SECONDS PLACE WHEN THE SECONDS ARE SINGLE DIGIT,
    //SAME WITH MINUTES, BUT NOT FOR HOURS
    void show() {
        cout << "The Current Time is: ";
        if (is24Hour) {
            cout << hours << ":" << minutes << ":" << seconds;
        } else {
            int tempHours;
            if (hours % 12 == 0){
                tempHours = 12;
            } else {
                tempHours = hours % 12;
            }

            if (hours >= 12) {
                cout << tempHours << ":" << minutes << ":" << seconds << " PM";
            } else {
                if (hours == 0) {
                    cout << "12" << ":" << minutes << ":" << seconds << " AM";
                }
                cout << tempHours << ":" << minutes << ":" << seconds << " AM";
            }
        }
    }

    void tick() {
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

};

#endif
