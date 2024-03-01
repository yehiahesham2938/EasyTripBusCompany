#ifndef EASYTRIPBUSCOMPANY_STATION_H
#define EASYTRIPBUSCOMPANY_STATION_H

#include <iostream>
#include "Buses.h"
#include"Passenger.h"
#include <cstdlib>
#include <ctime>
#include "DataStructures/Queue.h"

using namespace std;
struct BusNode {
    Bus* bus;
    BusNode* next;
    BusNode* prev;

    BusNode(Bus* b, BusNode* n = nullptr, BusNode* p = nullptr) : bus(b), next(n), prev(p) {}
};
class Station
        {
protected:
    int stationID;
    int stationTime;

    Queue<Passenger> finishList;

    BusNode* busesList;
    priorityQueue<Passenger> passengersQueue;
    Queue<NormalPassenger> NormalPassengersQueue;
    priorityQueue<SpecialCategoriesPassengers> SpecialPassengersQueue;
    priorityQueue<SpecialCategoriesPassengers> AgedPassengersQueue; // these are the waiting passengers
    priorityQueue<SpecialCategoriesPassengers> PodPassengersQueue;
    priorityQueue<SpecialCategoriesPassengers> PregnantPassengersqueue;
    Queue<WheelchairPassengers> WheelchairPassengersQueue;


public:
    Station(int stationID, int stationTime) : stationID(stationID), stationTime(stationTime) {}

    void setstationid(int stationId)
    {
        stationId = stationID;
    }
    void setstationTime(int stationtime)
    {
        stationtime = stationTime;
    }

    void addBus(Bus* bus) {
        BusNode* newNode = new BusNode(bus);
        if (!busesList) {

            busesList = newNode;
        } else {
            BusNode* temp = busesList;
            while (temp->next) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    int getNumberOfPassengers()
    {
        return passengersQueue.getCount();
    }

    Queue<WheelchairPassengers>& getWheelchairPassengersQueue() {
        return WheelchairPassengersQueue;
    }

    Queue<NormalPassenger>& getNormalPassengersQueue() {
        return NormalPassengersQueue;
    }

    priorityQueue<SpecialCategoriesPassengers> getSpecialPassengersQueue() {
        return SpecialPassengersQueue;
    }

    priorityQueue<SpecialCategoriesPassengers>& getAgedPassengersQueue()
    {
        return AgedPassengersQueue;
    }

    priorityQueue<SpecialCategoriesPassengers>& getPodPassengersQueue()
    {
        return PodPassengersQueue;
    }

    priorityQueue<SpecialCategoriesPassengers>& getPregnantPassengersQueue()
    {
        return PregnantPassengersqueue;
    }

    void enqueueWheelchairpassenger(WheelchairPassengers passenger) {
        WheelchairPassengersQueue.enqueue(passenger);
        passengersQueue.enqueue(passenger, 0);
    }

    void dequeueWheelchairpassenger() {
        WheelchairPassengersQueue.dequeue();
        passengersQueue.dequeue();
    }


    void displayWCP()
    {
        Node<WheelchairPassengers> *curr;
        curr = WheelchairPassengersQueue.getFront();
        while (curr != nullptr) {
            cout << curr->data.getpassengerOnOffTime() << " ";
            cout << curr->data.getPassengerStartStation() << " ";
            cout << curr->data.getPassengerEndStation() << endl;
            curr = curr->next;
        }
    }
    void enqueuenormalpassenger(NormalPassenger passenger)
    {
        NormalPassengersQueue.enqueue(passenger);
        passengersQueue.enqueue(passenger, 2);
    }

    void dequeuenormalpassenger()
    {
        NormalPassengersQueue.dequeue();
        passengersQueue.dequeue();
    }

    void displayNP()
    {
        Node<NormalPassenger> *curr;
        curr = NormalPassengersQueue.getFront();
        while (curr != nullptr)
        {
            cout << curr->data.getpassengerOnOffTime() << " ";
            cout << curr->data.getPassengerStartStation() << " ";
            cout << curr->data.getPassengerEndStation() << endl;

            curr = curr->next;
        }
    }

    void enqueuePassenger(SpecialCategoriesPassengers SpecialPassenger, int priority)
    {
        SpecialPassengersQueue.enqueue(SpecialPassenger, priority);
        passengersQueue.enqueue(SpecialPassenger, 3);
    }

    void dequeuespecialpassenger()
    {
        SpecialPassengersQueue.dequeue();
        passengersQueue.dequeue();
    }

    void displaySCP()
    {
        Node<SpecialCategoriesPassengers> *curr;
        curr = SpecialPassengersQueue.getFront();
        while (curr != nullptr)
        {
            cout << curr->data.getpassengerOnOffTime() << " ";
            cout << curr->data.getPassengerStartStation() << " ";
            cout << curr->data.getPassengerEndStation() << endl;
            curr = curr->next;
        }
    }

    void simulate() {

        if (stationTime >= 240 && stationTime <= 1320) {
            cout << "Station ID: " << stationID << " - Working hours simulation" << endl;




            BusNode* temp = busesList;
            while (temp) {
                cout << "   Bus Release: Bus Capacity: " << temp->bus->getBusCapacity() << endl;


                int randomNumber = rand() % 100 + 1;


                if (randomNumber >= 1 && randomNumber <= 25) {
                    cout << "   Moving one SP passenger to the Finish list" << endl;
//                    moveWPPassengerToFinishList
                }

                else if (randomNumber >= 26 && randomNumber <= 30) {
                    cout << "   Moving one WP passenger to the Finish list" << endl;
//                    moveWPPassengerToFinishList
                }

                else if (randomNumber >= 50 && randomNumber <= 60) {
                    cout << "   Moving one NP passenger to the Finish list" << endl;

//                    moveWPPassengerToFinishList
                }

                temp = temp->next;
            }
        } else {
            cout << "Station ID: " << stationID << " - Off-hours activities" << endl;
        }
    }

};


#endif //EASYTRIPBUSCOMPANY_STATION_H