
#ifndef EASYTRIPBUSCOMPANY_TIMESIMULATION_H
#define EASYTRIPBUSCOMPANY_TIMESIMULATION_H

#include <iostream>

using namespace std;

class SimulationTime
        {
private:
    int hours;
    int minutes;

    void normalizeTime()
    {
        hours = (hours + minutes / 60) % 24;
        minutes %= 60;
    }
public:
    SimulationTime(int hours, int minutes) : hours(hours), minutes(minutes)
    {
        normalizeTime();
    }

    void setHours(int newHours) {
        hours = newHours;
        normalizeTime();
    }
    void setMinutes(int newMinutes) {
        minutes = newMinutes;
        normalizeTime();
    }

    int getHours()  {
        return hours;
    }

    int getMinutes()  {
        return minutes;
    }

    string displayTime()
    {
        if (hours < 10)
        {
            cout << "0";
        }
        cout << hours << ":";
        if (minutes < 10)
        {
            cout << "0";
        }
        cout << minutes;
    }

    void advanceTime(int AddMinutes)
    {
        minutes += AddMinutes;
        normalizeTime();
    }

};

#endif //EASYTRIPBUSCOMPANY_TIMESIMULATION_H
