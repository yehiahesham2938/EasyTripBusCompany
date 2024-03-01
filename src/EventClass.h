#ifndef EASYTRIPBUSCOMPANY_EVENTCLASS_H
#define EASYTRIPBUSCOMPANY_EVENTCLASS_H
#include <iostream>
#include "Passenger.h"
#include "Buses.h"
#include "Station.h"
#include "TimeSimulation.h"

using namespace std;

class Event
{
protected:
    string EventType;
    string PassengerType;
    SimulationTime EventTime;
    int ID,StartStation,EndStation;
public:
    Event(string eventType, string passengerType, SimulationTime eventTime, int id, int startStation, int endStation)
            : EventType(eventType), PassengerType(passengerType), EventTime(eventTime), ID(id), StartStation(startStation),
              EndStation(endStation) {}

    virtual void Execute() = 0;

};
class ArrivalEvent : public Event {
private:
    string specialType;
public:
    ArrivalEvent(string eventType, string passengerType, SimulationTime eventTime, int id, int startStation, int endStation)
            : Event(eventType, passengerType, eventTime, id, startStation, endStation) {}

    void Execute() override
    {

        Station station(0, 0);
        if (PassengerType == "SP") {
            SpecialCategoriesPassengers specialPassenger(EventTime, 0, StartStation, EndStation);

            cout << "Enter special type (aged, pod, pregnant): ";
            cin >> specialType;

            int priority;
            if (specialType == "aged" || specialType == "Aged")
            {
                priority = 3;
            }
            if (specialType == "pod" || specialType == "POD")
            {
                priority = 2;
            }
            if (specialType == "pregnant" || specialType == "Pregnant")
            {
                priority = 1;
            }

            station.enqueuePassenger(specialPassenger, priority);
        }
        if (PassengerType == "WP")
        {
            WheelchairPassengers wheelchairPassenger(EventTime, 0, StartStation, EndStation);

            station.enqueueWheelchairpassenger(wheelchairPassenger);
        }
        if (PassengerType == "NP")
        {
            NormalPassenger normalPassenger(EventTime, 0, StartStation, EndStation);
            station.enqueuenormalpassenger(normalPassenger);
        }
    }
};

class LeaveEvent : public Event {
public:
    LeaveEvent(string eventType, SimulationTime eventTime, int id, int startStation, int endStation)
            : Event(eventType, "", eventTime, id, startStation, endStation) {}

    void Execute() override {
        if (StartStation == EndStation) {
            NormalPassenger normalPassenger(EventTime, 0, StartStation, EndStation);
            Station station(0, 0);

            station.dequeuenormalpassenger();
        }
    }
};

#endif //EASYTRIPBUSCOMPANY_EVENTCLASS_H