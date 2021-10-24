#ifndef AVS_02_TRUCK_H
#define AVS_02_TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
public:
    Truck(int input[4]);

    // Creating truck with random
    Truck();

    void out(FILE * fp) override;

    double distance() override;

private:
    int capacity;
    double consumption;
    int lifting;
};


#endif //AVS_02_TRUCK_H
