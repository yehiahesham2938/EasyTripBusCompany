//
// Created by yehia on 12/1/2023.
//

#ifndef EASYTRIPBUSCOMPANY_BUSES_H
#define EASYTRIPBUSCOMPANY_BUSES_H

#include <iostream>
#include "DataStructures/Queue.h"
#include "Passenger.h"
#include <fstream>
class Bus
{
protected:
    int BusCapacity, tripsBeforeCheckup, checkupDuration;

public:

    Queue<Bus> BusesQueue;
    Bus(int BusCapacity, int tripsBeforeCheckup, int checkupDuration):BusCapacity(BusCapacity), tripsBeforeCheckup(tripsBeforeCheckup), checkupDuration(checkupDuration){}

    int getBusCapacity()
    {
        return BusCapacity;
    }


    int getTripsBeforeChecukup()
    {
        return tripsBeforeCheckup;
    }
    int getcheckupDuration()
    {
        return checkupDuration;
    }
};

class WBus:public Bus {
private:
    Queue<WBus> wheelchairBusesQueue;
    Queue<WheelchairPassengers> ONBOARDWheelchairPassengersQueue;
protected:


    int WBusNumbers;
public:
    WBus(int BusCapacity, int tripsBeforeCheckup, int checkupDuration) : Bus(BusCapacity, tripsBeforeCheckup,
                                                                             checkupDuration) {}

    void setNumberOfWBuses(int WbusNumbers)
    {
        WBusNumbers = WbusNumbers;
    }
    int getNumberOfWBuses()
    {
        return WBusNumbers;
    }
    void enqueueWBUS(WBus wheelchairbus )
    {
        for (int i = 0; i < WBusNumbers; ++i)
        {
            wheelchairBusesQueue.enqueue(wheelchairbus);
            BusesQueue.enqueue(wheelchairbus);
        }
    }

    void dequeueWBUS()
    {
        wheelchairBusesQueue.dequeue();
        BusesQueue.dequeue();
    }


    void enqueueWPassengerONBOARD(WheelchairPassengers wheelchairPassenger)
    {
        ONBOARDWheelchairPassengersQueue.enqueue(wheelchairPassenger);
    }

    void dequeueWPassengerONBOARD()
    {
        ONBOARDWheelchairPassengersQueue.dequeue();
    }

    void display()
    {
        Node<WBus> *curr;
        curr = wheelchairBusesQueue.getFront();
        while (curr != nullptr)
        {
            cout << "Bus Capacity: "<< curr->data.getBusCapacity() << " ";
            cout << "Trips before checkup: "<< curr->data.getTripsBeforeChecukup() << " ";
            cout<< "checkup Duration: " << curr->data.getcheckupDuration() << " ";
            cout << "Num Of Buses: "<< curr->data.getNumberOfWBuses() << endl;
            curr = curr->next;
        }
    }

};
class MBus:public Bus {
protected:
    int MBusNumbers;
    Queue<MBus> MixedBusesQueue;
    Queue<Passenger> PassengersONBoard;

public:
    MBus(int BusCapacity, int tripsBeforeCheckup, int checkupDuration) : Bus(BusCapacity, tripsBeforeCheckup,
                                                                             checkupDuration) {}

    void setNumberOfMixedBuses(int MbusNumbers)
    {
        MBusNumbers = MbusNumbers;
    }
    int getNumberofMixedBuses()
    {
        return MBusNumbers;
    }

    void enqueueMBUS(MBus MixedBus )
    {
        for (int i = 0; i < MBusNumbers; ++i)
        {
            MixedBusesQueue.enqueue(MixedBus);
            BusesQueue.enqueue(MixedBus);
        }
    }

    void dequeueMBUS()
    {
        MixedBusesQueue.dequeue();
        BusesQueue.dequeue();
    }



    void enqueueMPassengerONBOARD(Passenger passenger)
    {
        PassengersONBoard.enqueue(passenger);

    }

    void dequeueMPassengerONBOARD()
    {
        PassengersONBoard.dequeue();
    }

    void displayMBuses()
    {
        Node<MBus> *curr;
        curr = MixedBusesQueue.getFront();
        while (curr != nullptr)
        {
            cout << "Bus Capacity: "<< curr->data.getBusCapacity() << " ";
            cout << "Trips before checkup: "<< curr->data.getTripsBeforeChecukup() << " ";
            cout<< "checkup Duration: " << curr->data.getcheckupDuration() << " ";
            cout << "Num Of Buses: "<< curr->data.getNumberofMixedBuses()<< endl;
            curr = curr->next;
        }
    }
};
#endif //EASYTRIPBUSCOMPANY_BUSES_H