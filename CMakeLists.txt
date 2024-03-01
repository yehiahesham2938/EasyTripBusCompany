cmake_minimum_required(VERSION 3.26)
project(EasyTripBusCompany)

set(CMAKE_CXX_STANDARD 17)

add_executable(EasyTripBusCompany main.cpp
        src/EventClass.h
        src/Station.h
        src/Company.h
        src/UI.h
        src/Passenger.h
        src/Buses.h
        src/DataStructures/Node.h
        src/DataStructures/Queue.h
        src/DataStructures/Pri-Queues.h
        src/TimeSimulation.h
        src/DataStructures/LinkedList.h)
