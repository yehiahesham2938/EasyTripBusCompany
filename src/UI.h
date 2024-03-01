//
// Created by yehia on 12/1/2023.
//

#ifndef EASYTRIPBUSCOMPANY_UI_H
#define EASYTRIPBUSCOMPANY_UI_H

#include <iostream>
#include <string>
#include "EventClass.h"
#include "Buses.h"
#include <fstream>
#include "Station.h"
using namespace std;
class UI
{
private:
    int stations=0, minBetweenStations;
    int numWBus, numMBus;
    int capacityWBus, capacityMBus;
    int tripsBeforeCheckup, checkupDuration;
    int maxW, getOnOffTime;
    int numEvents;
    int countNP=0, countSP=0, countWP=0;


public:
    void start() {
        int mode;
        cout << "Choose mode:" << endl << " 1. Interactive Mode" << endl << " 2. Silent Mode " << endl;
        cin >> mode;

        if (mode == 1)
        {
            readInputFromTerminal();
            outputfile();
        } else if (mode == 2)
        {
            silentMode();

        } else {
            cout << "Invalid choice. Exiting program.\n";
        }
    }

    void readInputFile() {


        ifstream inputfile("input.txt");
        inputfile.open("input.txt");
        cout << "reading the number of stations and minutes between stations: " << endl;
        inputfile >> stations >> minBetweenStations;
        cout << "Number of Stations: " << stations << ", Minutes Between Stations: " << minBetweenStations << "\n";

        cout << "reading the number of WBus and MBus: "<< endl;
        inputfile >> numWBus >> numMBus;
        int getNumWBus =0;
        int getNumMBus =0;
        getNumWBus = numWBus;
        getNumMBus = numMBus;



        cout << "reading the capacity of WBus and MBus: " << endl;
        inputfile >> capacityWBus >> capacityMBus;

        cout << "reading the number of trips before checkup and checkup duration: "   << endl;
        inputfile >> tripsBeforeCheckup >> checkupDuration;

        cout << "reading maxW (minutes) and get on/off time (seconds): "  << endl;
        inputfile >> maxW >> getOnOffTime;

        cout << "reading the number of events: " << endl;
        inputfile >> numEvents;

        WBus wBus(capacityWBus, tripsBeforeCheckup, checkupDuration);
        wBus.setNumberOfWBuses(numWBus);
        wBus.enqueueWBUS(wBus);

        MBus mBus(capacityMBus, tripsBeforeCheckup, checkupDuration);
        mBus.setNumberOfMixedBuses(numMBus);
        mBus.enqueueMBUS(mBus);


        for (int i = 0; i < numEvents; ++i) {
            string event, passengerType, specialType;
            SimulationTime eventTime(00, 00);

            int id, startStation, endStation;

            cout << endl << "reading event type (A for Arrival, L for Leave): " << endl;
            inputfile >> event;

            if (event == "L") {
                int hours, minutes;

                cout << "reading leave event time (hours minutes): " << endl;
                inputfile >> hours >> minutes;
                eventTime.setHours(hours);
                eventTime.setMinutes(minutes);

                cout << "reading ID, start station, and end station: " << endl;
                inputfile >> id >> startStation >> endStation;
            } else if (event == "A") {
                cout << "reading passenger type (NP, WP, SP): " << endl;
                inputfile >> passengerType;

                int hours, minutes;

                cout << "reading arrival event time (hours minutes): " << endl;
                inputfile >> hours >> minutes;
                eventTime.setHours(hours);
                eventTime.setMinutes(minutes);

                cout << "reading ID, start station, and end station: " << endl;
                inputfile >> id >> startStation >> endStation;

                if (passengerType == "SP") {
                    cout << "reading special type (aged, pod, pregnant): " << endl;
                    inputfile >> specialType;
                }
            }
            if (event == "A") {
                Station station(stations, minBetweenStations);
                if (passengerType == "NP") {
                    ArrivalEvent arrivalEvent(event, passengerType, eventTime, id, startStation, endStation);
                    NormalPassenger normalPassenger(eventTime, getOnOffTime, startStation, endStation);
                    station.enqueuenormalpassenger(normalPassenger);
                    mBus.enqueueMPassengerONBOARD(normalPassenger);
                    countNP++;
                    arrivalEvent.Execute();
                } else if (passengerType == "WP") {
                    ArrivalEvent arrivalEvent(event, passengerType, eventTime, id, startStation, endStation);
                    WheelchairPassengers wheelchairPassengers(eventTime, getOnOffTime, startStation, endStation);
                    station.enqueueWheelchairpassenger(wheelchairPassengers);
                    wBus.enqueueWPassengerONBOARD(wheelchairPassengers);
                    countWP++;
                    arrivalEvent.Execute();
                } else if (passengerType == "SP") {
                    ArrivalEvent arrivalEvent(event, passengerType, eventTime, id, startStation, endStation);
                    SpecialCategoriesPassengers specialCategoriesPassengers(eventTime, getOnOffTime, startStation,
                                                                            endStation);
                    station.enqueuePassenger(specialCategoriesPassengers, 3);
                    mBus.enqueueMPassengerONBOARD(specialCategoriesPassengers);
                    countSP++;
                    arrivalEvent.Execute();
                }
            } else if (event == "L") {
                LeaveEvent leaveEvent(event, eventTime, id, startStation, endStation);

                leaveEvent.Execute();
            }
        }

        cout << "__________________________________________________________" << endl;
        cout << "total Number of Buses: " << getNumMBus + getNumWBus << endl << "MBuses: " << getNumMBus << endl
             << "WBuses: " << getNumWBus << endl;
        cout << "number of passengers: " << countSP + countWP + countNP << " [SP: " << countSP << ", NP: "
             << countNP << ",WP: " << countWP << " ]" << endl;
        inputfile.close();

    }
    void readInputFromTerminal() {
        cout << "Enter the number of stations and minutes between stations: " << endl;
        cin >> stations >> minBetweenStations;
        cout << "Number of Stations: " << stations << ", Minutes Between Stations: " << minBetweenStations << "\n";

        cout << "Enter the number of WBus and MBus: " << endl;
        cin >> numWBus >> numMBus;

        int getNumWBus = numWBus;
        int getNumMBus = numMBus;

        cout << "Enter the capacity of WBus and MBus: " << endl;
        cin >> capacityWBus >> capacityMBus;

        cout << "Enter the number of trips before checkup and checkup duration: " << endl;
        cin >> tripsBeforeCheckup >> checkupDuration;

        cout << "Enter maxW (minutes) and get on/off time (seconds): " << endl;
        cin >> maxW >> getOnOffTime;

        cout << "Enter the number of events: " << endl;
        cin >> numEvents;

        WBus wBus(capacityWBus, tripsBeforeCheckup, checkupDuration);
        wBus.setNumberOfWBuses(numWBus);
        wBus.enqueueWBUS(wBus);

        MBus mBus(capacityMBus, tripsBeforeCheckup, checkupDuration);
        mBus.setNumberOfMixedBuses(numMBus);
        mBus.enqueueMBUS(mBus);

        for (int i = 0; i < numEvents; ++i) {
            string event, passengerType, specialType;
            SimulationTime eventTime(00, 00);

            int id, startStation, endStation;

            cout << endl << "Enter event type (A for Arrival, L for Leave): " << endl;
            cin >> event;

            if (event == "L") {
                int hours, minutes;

                cout << "Enter leave event time (hours minutes): " << endl;
                cin >> hours >> minutes;
                eventTime.setHours(hours);
                eventTime.setMinutes(minutes);

                cout << "Enter ID, start station, and end station: " << endl;
                cin >> id >> startStation >> endStation;
            } else if (event == "A") {
                cout << "Enter passenger type (NP, WP, SP): " << endl;
                cin >> passengerType;

                int hours, minutes;

                cout << "Enter arrival event time (hours minutes): " << endl;
                cin >> hours >> minutes;
                eventTime.setHours(hours);
                eventTime.setMinutes(minutes);

                cout << "Enter ID, start station, and end station: " << endl;
                cin >> id >> startStation >> endStation;

//                if (passengerType == "SP") {
//                    cout << "Enter special type (aged, pod, pregnant): " << endl;
//                    cin >> specialType;
//                }
            }
            if (event == "A") {
                Station station(stations, minBetweenStations);
                if (passengerType == "NP") {
                    ArrivalEvent arrivalEvent(event, passengerType, eventTime, id, startStation, endStation);
                    NormalPassenger normalPassenger(eventTime, getOnOffTime, startStation, endStation);
                    station.enqueuenormalpassenger(normalPassenger);
                    mBus.enqueueMPassengerONBOARD(normalPassenger);
                    countNP++;
                    arrivalEvent.Execute();
                } else if (passengerType == "WP") {
                    ArrivalEvent arrivalEvent(event, passengerType, eventTime, id, startStation, endStation);
                    WheelchairPassengers wheelchairPassengers(eventTime, getOnOffTime, startStation, endStation);
                    station.enqueueWheelchairpassenger(wheelchairPassengers);
                    wBus.enqueueWPassengerONBOARD(wheelchairPassengers);
                    countWP++;
                    arrivalEvent.Execute();
                } else if (passengerType == "SP") {
                    ArrivalEvent arrivalEvent(event, passengerType, eventTime, id, startStation, endStation);
                    SpecialCategoriesPassengers specialCategoriesPassengers(eventTime, getOnOffTime, startStation,
                                                                            endStation);
                    station.enqueuePassenger(specialCategoriesPassengers, 3);
                    mBus.enqueueMPassengerONBOARD(specialCategoriesPassengers);
                    countSP++;
                    arrivalEvent.Execute();
                }
            } else if (event == "L") {
                LeaveEvent leaveEvent(event, eventTime, id, startStation, endStation);

                leaveEvent.Execute();
            }
        }

        cout << "__________________________________________________________" << endl;
        cout << "Total Number of Buses: " << getNumMBus + getNumWBus << endl << "MBuses: " << getNumMBus << endl
             << "WBuses: " << getNumWBus << endl;
        cout << "Number of passengers: " << countSP + countWP + countNP << " [SP: " << countSP << ", NP: "
             << countNP << ", WP: " << countWP << " ]" << endl;

    }


    void silentMode()
    {

        cout << "silent Mode" << endl;
        cout <<"Simulation Starts..." << endl;
        cout <<"Simulation ends, " << endl;
        outputfile();
    }
    void outputfile() {

        ofstream outputFile("output.txt");
        if (outputFile.is_open()) {
            outputFile << "total Number of Buses: " << numMBus + numWBus << endl << "MBuses: " << numMBus << endl
                       << "WBuses: " << numWBus << endl;
            outputFile << "number of passengers: " << countSP + countWP + countNP << " [SP: " << countSP << ", NP: "
                       << countNP << ",WP: " << countWP << " ]" << endl;

            outputFile.close();
            cout << "Output file created" << endl;
        } else {
            cout << "Error creating output.txt. Exiting program.\n";
        }
    }

};
#endif //EASYTRIPBUSCOMPANY_UI_H
