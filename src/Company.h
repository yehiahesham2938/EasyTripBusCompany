#ifndef EASYTRIPBUSCOMPANY_COMPANY_H
#define EASYTRIPBUSCOMPANY_COMPANY_H

#include <iostream>
#include "Station.h"
#include "EventClass.h"
#include "DataStructures/LinkedList.h"
#include "DataStructures/Node.h"
#include "Buses.h"
#include "passenger.h"

using namespace std;

class Company : public Station, public WBus, public MBus {
private:
    LinkedList<WBus> Wheelebuslist;
    LinkedList<MBus> MbusList;
    LinkedList<Station> StationsList;
    LinkedList<ArrivalEvent> ArrivalEventsList;
    LinkedList<LeaveEvent> LeaveEventsList;
    LinkedList<Passenger> forwardPassengers;
    LinkedList<Passenger> backwardPassengers;

public:
    void company(int stationId, int WBusNumber) {
        stationId = stationID;
        WBusNumber = WBusNumbers;
        int totalNumberOfBuses = WBusNumbers + MBusNumbers;

        for (int i = 0; i < totalNumberOfBuses; ++i) {
            if (i % 2 == 0) {
                WBus wbus(4, 5, 6);
                Wheelebuslist.insert(wbus);
            } else {
                MBus mbus(1, 2, 3);
                MbusList.insert(mbus);
            }
        }
    }

    void addStation() {
        Station stationn(1, 2);
        StationsList.insert(stationn);
    }

    void addArrivalEvent() {
        SimulationTime simulationTime(00, 00);
        ArrivalEvent event("A", "Np", simulationTime, 1, 2, 3);
        ArrivalEventsList.insert(event);
    }

    void addLeaveEvent() {
        SimulationTime simulationTime(00, 00);
        LeaveEvent event("L", simulationTime, 1, 2, 3);
        LeaveEventsList.insert(event);
    }

//    void addPassenger(int stationId, Direction direction) {
//        SimulationTime currentTime(00, 00);
//        SimulationTime simulationTime(22 , 00);
//        if (stationTime >= 240 && stationTime <= 1320) {
//            // Working hours
//            if (currentTime <= simulationTime) {
//                Passenger passenger(currentTime, 0 ,0,0 );
//                if (direction == Direction::Forward) {
//                    forwardPassengers.insert(passenger);
//                } else {
//                    backwardPassengers.insert(passenger);
//                }
//            } else {
//                cout << "Passenger cannot board after 22:00." << endl;
//            }
//        } else {
//            cout << "Passenger cannot board during off-hours." << endl;
//        }
//    }

    void releaseBuses() {
        if (stationTime >= 240 && stationTime <= 1320) {
            // Working hours
            int totalNumberOfBuses = WBusNumbers + MBusNumbers;

            for (int i = 0; i < totalNumberOfBuses; ++i) {
                if (i % 2 == 0) {
                    WBus wbus(4, 5, 6);
                    Wheelebuslist.insert(wbus);
                } else {
                    MBus mbus(1, 2, 3);
                    MbusList.insert(mbus);
                }
            }
        }
    }

    void simulate(int minute) {

        if (stationTime >= 240 && stationTime <= 1320) {
            if (minute % 15 == 0) {

                releaseBuses();
            }
        }
    }

//    void collectStatistics(const string& outputFileName) {
//        ofstream outputFile(outputFileName);
//
//        if (!outputFile.is_open()) {
//            cout << "Error opening output file: " << outputFileName << endl;
//            return;
//        }
//
//        // Collect statistics
//        int totalWheelBuses = Wheelebuslist.size();
//        int totalMixedBuses = MbusList.size();
//        int totalStations = StationsList.size();
//        int totalArrivalEvents = ArrivalEventsList.size();
//        int totalLeaveEvents = LeaveEventsList.size();
//        int totalForwardPassengers = forwardPassengers.size();
//        int totalBackwardPassengers = backwardPassengers.size();

//        cout << "Total Wheel Buses: " << totalWheelBuses << endl;
//        cout << "Total Mixed Buses: " << totalMixedBuses << endl;
//        cout << "Total Stations: " << totalStations << endl;
//        cout << "Total Arrival Events: " << totalArrivalEvents << endl;
//        cout << "Total Leave Events: " << totalLeaveEvents << endl;
//        cout << "Total Forward Passengers: " << totalForwardPassengers <<endl;
//        cout << "Total Backward Passengers: " << totalBackwardPassengers << endl;
//
//
//    }

    ~Company() {
        Wheelebuslist.DeleteAll();
        MbusList.DeleteAll();
        StationsList.DeleteAll();
        ArrivalEventsList.DeleteAll();
        LeaveEventsList.DeleteAll();
    }
};

#endif //EASYTRIPBUSCOMPANY_COMPANY_H
