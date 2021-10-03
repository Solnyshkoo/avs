//
// Created by Ksenia Petrova on 01.10.2021.
//

#ifndef AVS_CPP_01_TRUCK_H
#define AVS_CPP_01_TRUCK_H

#include "fstream"

struct truck {
    int capacity;
    double consumption;
    int lifting;
};

void In(truck &t, int inputs[4]);

void Out(truck &t, FILE * fp);

void InRnd(truck &t);

double Distance(truck &t);

#endif //AVS_CPP_01_TRUCK_H
