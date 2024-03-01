#ifndef EASYTRIPBUSCOMPANY_PASSENGER_H
#define EASYTRIPBUSCOMPANY_PASSENGER_H

#include <iostream>
#include <string>
#include "DataStructures/Queue.h"
#include "TimeSimulation.h"
#include "DataStructures/Pri-Queues.h"

using namespace std;
enum class Direction {
    Forward,
    Backward
};
class Passenger {
protected:
    SimulationTime ArrivalTime;
    int passengerOnOffTime, passengerStartStation, passengerEndStation;

public:

    Passenger(SimulationTime arrivalTime, int passengerOnOffTime, int passengerStartStation, int passengerEndStation)
            : ArrivalTime(arrivalTime), passengerOnOffTime(passengerOnOffTime),
              passengerStartStation(passengerStartStation), passengerEndStation(passengerEndStation) {}

    SimulationTime getArrivalTime()
    {
        return ArrivalTime;
    }

    int getpassengerOnOffTime()
    {
        return passengerOnOffTime;
    }

    int getPassengerStartStation()
    {
        return passengerStartStation;
    }

    int getPassengerEndStation()
    {
        return passengerEndStation;
    }


};

class NormalPassenger : public Passenger {
protected:
    int normalPassengerCount;
public:
    NormalPassenger(SimulationTime arrivalTime, int passengerOnOffTime, int passengerStartStation, int passengerEndStation)
            : Passenger(arrivalTime, passengerOnOffTime, passengerStartStation, passengerEndStation) {   normalPassengerCount++;
    }


     int getNormalPassengerCount() {
        return normalPassengerCount;
    }

};

class SpecialCategoriesPassengers : public Passenger {
protected:

    int specialPassengerCount;
public:
    SpecialCategoriesPassengers(SimulationTime arrivalTime, int passengerOnOffTime, int passengerStartStation, int passengerEndStation)
            : Passenger(arrivalTime, passengerOnOffTime, passengerStartStation, passengerEndStation) {        specialPassengerCount++;
    }

    string type;

    int getSpecialPassengerCount() {
        return specialPassengerCount;
    }

};

class WheelchairPassengers : public Passenger {
protected:
    int wheelchairPassengerCount;
public:
    WheelchairPassengers(SimulationTime arrivalTime, int passengerOnOffTime, int passengerStartStation,
                         int passengerEndStation)
            : Passenger(arrivalTime, passengerOnOffTime, passengerStartStation, passengerEndStation) {        wheelchairPassengerCount++;
    }
    int getWheelchairPassengerCount() {
        return wheelchairPassengerCount;
    }


};

#endif //EASYTRIPBUSCOMPANY_PASSENGER_H
