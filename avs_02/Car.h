#ifndef AVS_02_CAR_H
#define AVS_02_CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
public:
    // Creating car from given values
    Car(int input[4]);

    // Creating car with random
    Car();

    void out(FILE * fp) override;

    double distance() override;

private:
    int capacity;
    double consumption;
    short max_speed;
};


#endif //AVS_02_CAR_H
