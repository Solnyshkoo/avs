//
// Created by Ksenia Petrova on 01.10.2021.
//

#ifndef AVS_CPP_01_BUS_H
#define AVS_CPP_01_BUS_H

#include "fstream"

struct bus {
    int capacity;
    double consumption;
    short person_capacity;
};

void In(bus &t, int inputs[4]);

void Out(bus &t, FILE * fp);

double Distance(bus &t);

void InRnd(bus &t);

#endif //AVS_CPP_01_BUS_H
