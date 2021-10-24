#ifndef AVS_02_VEHICLE_H
#define AVS_02_VEHICLE_H


#include <cstdio>
#include <fstream>


class Vehicle {
public:
    // Virtual common methods

    virtual double distance() {};

    virtual void out(FILE * fp) {};
};


#endif //AVS_02_VEHICLE_H
