//
// Created by Ksenia Petrova on 01.10.2021.
//

#include "vehicle.h"
#include <fstream>

// Ввод обобщенной фигуры
vehicle *In(int inputs[4]) {
    vehicle *sp;
    int k = inputs[0];
    switch (k) {
        case 1:
            sp = new vehicle;
            sp->k = vehicle::TRUCK;
            In(sp->t, inputs);
            return sp;
        case 2:
            sp = new vehicle;
            sp->k = vehicle::BUS;
            In(sp->b, inputs);
            return sp;
        case 3:
            sp = new vehicle;
            sp->k = vehicle::CAR;
            In(sp->c, inputs);
            return sp;
        default:
            return 0;
    }
}

// Случайный ввод обобщенной фигуры
vehicle *InRnd() {
    vehicle *sp;
    auto k = rand() % 3 + 1;
    switch(k) {
        case 1:
            sp = new vehicle;
            sp->k = vehicle::TRUCK;
            InRnd(sp->t);
            return sp;
        case 2:
            sp = new vehicle;
            sp->k = vehicle::BUS;
            InRnd(sp->b);
            return sp;
        case 3:
            sp = new vehicle;
            sp->k = vehicle::CAR;
            InRnd(sp->c);
            return sp;
        default:
            return 0;
    }
}

// Вывод обобщенной фигуры
void Out(vehicle &v, FILE * fp) {
    switch(v.k) {
        case vehicle::TRUCK:
            Out(v.t, fp);
            break;
        case vehicle::BUS:
            Out(v.b, fp);
            break;
        case vehicle::CAR:
            Out(v.c, fp);
            break;
        default:
            fprintf(fp, "Incorrect vehicle type!");
    }
}


double Distance(vehicle &v) {
    switch(v.k) {
        case vehicle::TRUCK:
            return Distance(v.t);
        case vehicle::BUS:
            return Distance(v.b);
        case vehicle::CAR:
            return Distance(v.c);
        default:
            return 0;
    }
}

