//
// Created by Ksenia Petrova on 01.10.2021.
//

#ifndef AVS_CPP_01_CAR_H
#define AVS_CPP_01_CAR_H

#include "fstream"

struct car {
    int capacity;
    double consumption;
    short max_speed;
};

void In(car &t, int inputs[4]);

void Out(car &t, FILE * fp);

double Distance(car &t);

void InRnd(car &t);


#endif //AVS_CPP_01_CAR_H
