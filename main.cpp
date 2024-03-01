#include <iostream>
using namespace std;
#include "src/Passenger.h"
#include "src/Buses.h"
#include "src/TimeSimulation.h"
#include "src/EventClass.h"
#include "src/UI.h"
int main()
{
//    SimulationTime arrivaltime(2,00);
//    SimulationTime arrivaltime2(12,23);
//    SimulationTime arrivaltime3(19,11);
//    SimulationTime arrivaltime4(4,78);
//
//
//    NormalPassenger normalPassenger(arrivaltime4, 20, 1, 5);
//
//    NormalPassenger np1(arrivaltime, 15, 2, 5);
//    NormalPassenger np2(arrivaltime3, 13, 1, 4);
//    NormalPassenger np3(arrivaltime2, 12, 3, 8);
//    NormalPassenger np4(arrivaltime, 16, 5, 7);
//
//    normalPassenger.enqueuenormalpassenger(normalPassenger);
//    normalPassenger.enqueuenormalpassenger(np1);
//    normalPassenger.enqueuenormalpassenger(np2);
//    normalPassenger.enqueuenormalpassenger(np3);
//    normalPassenger.enqueuenormalpassenger(np4);
//    normalPassenger.dequeuenormalpassenger();
//normalPassenger.display();
    //    cout << "\n_____________________________" << endl;
//    SimulationTime arrivaltime5(2,00);
//    SimulationTime arrivaltime6(12,23);
//    SimulationTime arrivaltime7(19,11);
//    SimulationTime arrivaltime8(4,78);
//
//    int prio = 0;
//    SpecialCategoriesPassengers specialCategoriesPassengers(arrivaltime5, 15, 2, 5);
//    SpecialCategoriesPassengers p1(arrivaltime6, 12, 2, 11);
//    SpecialCategoriesPassengers p2(arrivaltime7, 14, 3, 9);
//    SpecialCategoriesPassengers p3(arrivaltime8, 11, 6, 7);
//    specialCategoriesPassengers.enqueuePassenger(p3, prio );
//    specialCategoriesPassengers.enqueuePassenger(p1, prio );
//    specialCategoriesPassengers.enqueuePassenger(p2, prio );
//    specialCategoriesPassengers.display();

    cout << "\n_____________________________" << endl;
//    SimulationTime arrivaltime(2,00);
//    SimulationTime arrivaltime2(12,23);
//    SimulationTime arrivaltime3(19,11);
//    SimulationTime arrivaltime4(4,78);
//    WheelchairPassengers wheelchairPassengers(arrivaltime,15,1,4);
//    WheelchairPassengers wp1(arrivaltime2,15,1,4);
//    WheelchairPassengers wp2(arrivaltime3,15,1,4);
//    WheelchairPassengers wp3(arrivaltime4,15,1,4);
//    wheelchairPassengers.enqueueWheelchairpassenger(wheelchairPassengers);
//    wheelchairPassengers.enqueueWheelchairpassenger(wp1);
//    wheelchairPassengers.enqueueWheelchairpassenger(wp2);
//    wheelchairPassengers.enqueueWheelchairpassenger(wp3);
//    wheelchairPassengers.display();



//_________________________________________

//    WBus wBus(30, 5, 2);
//    wBus.setNumberOfWBuses(5);
//    wBus.enqueueWBUS(wBus);
//    wBus.display();
//
//    wBus.dequeueWBUS();
//    cout<<"after dequeue bus: "<< endl;
//    wBus.display();
//    cout << "______________________" << endl;
//    MBus mBus(15, 5, 2);
//    mBus.setNumberOfMixedBuses(4);
//    mBus.enqueueMBUS(mBus);
//    mBus.display();
//
//    mBus.dequeueMBUS();
//    cout<<"after dequeue bus: "<< endl;
//    mBus.display();
    ///////////////////////////////////////////////////
    /*Station station(10); 
    
    Bus bus1(30, 5, 2); 
    Bus bus2(25, 4, 3);
    station .addBusToStation(bus1);
    station .addBusToStation(bus2);

    
    station .displayBusesAtStation();

    
    station .generateRandomNumbersAndMoveToFinishList();

    
    station.displayBusesAtStation();
    // station.moveBusesBackward();

    //station.moveBusesForward(); */
//______________________________________________________
//SimulationTime testTime1(00,00);
//testTime1.advanceTime(240);
//testTime1.displayTime();
    UI ui;
    ui.start();

}
