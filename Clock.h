#ifndef CLOCK_H
#define CLOCK_H

using namespace std;

class Clock{
private:
    int hours;
    int minutes;
    int seconds;
    bool is24Hour;
    bool isAM;

public:
    Clock();
    Clock(int, int, int);
    Clock(int, int, int, bool, bool);
    void toggleFormat();
    void show();
    void tick();

};

#endif
