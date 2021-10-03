//
// Created by Ksenia Petrova on 01.10.2021.
//

#include "bus.h"


void In(bus &t, int inputs[4]) {
    t.capacity = inputs[1];
    t.consumption = inputs[2];
    t.person_capacity = inputs[3];
}

void Out(bus &t, FILE * fp) {
    fprintf(fp, "It is Bus: Fuel capacity = %d (litres), ", t.capacity);
    fprintf(fp, "Fuel consumption = %f (100km), ", t.consumption);
    fprintf(fp, "Maximum parson capacity = %d  (pers.). ", t.person_capacity);
    fprintf(fp, "Maximum distance = %f (km)\n", Distance(t));
}

void InRnd(bus &t) {
    t.consumption = static_cast<double> (rand() % 10 + 3) + static_cast<double> (rand() % 1000 + 10) / 1000.0;
    t.capacity = rand() % 40 + 30;
    t.person_capacity = rand() % 90 + 45;
}


double Distance(bus &t) {
    return (static_cast<double>(t.capacity)/t.consumption) * 100;
}