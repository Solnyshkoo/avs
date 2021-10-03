//
// Created by Ksenia Petrova on 01.10.2021.
//

#include "car.h"

void In(car &t, int inputs[4]) {
    t.capacity = inputs[1];
    t.consumption = inputs[2];
    t.max_speed = inputs[3];
}

void Out(car &t, FILE * fp) {
    fprintf(fp, "It is Car: Fuel capacity = %d (litres), ", t.capacity);
    fprintf(fp, "Fuel consumption = %f (100km), ", t.consumption);
    fprintf(fp, "Maximum speed = %d  (km/h). ", t.max_speed);
    fprintf(fp, "Maximum distance = %f (km)\n", Distance(t));
}

void InRnd(car &t) {
    t.consumption = static_cast<double> (rand() % 10 + 3) + static_cast<double> (rand() % 1000 + 10) / 1000.0;
    t.capacity = rand() % 40 + 30;
    t.max_speed = rand() % 100 + 60;
}

double Distance(car &t) {
    return (static_cast<double>(t.capacity)/t.consumption) * 100;
}