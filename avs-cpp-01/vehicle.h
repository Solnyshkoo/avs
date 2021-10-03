//
// Created by Ksenia Petrova on 01.10.2021.
//

#ifndef AVS_CPP_01_VEHICLE_H
#define AVS_CPP_01_VEHICLE_H

#include "car.h"
#include "bus.h"
#include "truck.h"
#include "fstream"

struct vehicle {
    enum key {TRUCK, BUS, CAR};
    key k;

    union {
        truck t;
        bus b;
        car c;
    };
};


// Ввод обобщенной фигуры
vehicle *In(int inputs[4]);

// Вывод обобщенной фигуры
void Out(vehicle &v, FILE* fp);

double Distance(vehicle &v);

vehicle *InRnd();

#endif //AVS_CPP_01_VEHICLE_H