#ifndef AVS_02_BUS_H
#define AVS_02_BUS_H

#include "Vehicle.h"

class Bus : public Vehicle {
public:
    // Creating bus from given values
    Bus(int input[4]);

    // Creating bus with random
    Bus();

    void out(FILE * fp) override;

    double distance() override;

private:
    int capacity;
    double consumption;
    short person_capacity;
};


#endif //AVS_02_BUS_H
