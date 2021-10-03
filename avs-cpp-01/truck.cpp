//
// Created by Ksenia Petrova on 01.10.2021.
//

#include "truck.h"

void In(truck &t, int inputs[4]) {
    t.capacity = inputs[1];
    t.consumption = inputs[2];
    t.lifting = inputs[3];
}

void Out(truck &t, FILE * fp) {
    fprintf(fp, "It is Truck: Fuel capacity = %d (litres), ", t.capacity);
    fprintf(fp, "Fuel consumption = %f (100km), ", t.consumption);
    fprintf(fp, "Lifting capacity = %d  (kg). ", t.lifting);
    fprintf(fp, "Maximum distance = %f (km)\n", Distance(t));
}

void InRnd(truck &t) {
    t.consumption = static_cast<double> (rand() % 10 + 3) + static_cast<double> (rand() % 1000 + 10) / 1000.0;
    t.capacity = rand() % 40 + 30;
    t.lifting = rand() % 3000 + 1500;
}


double Distance(truck &t) {
    return (static_cast<double>(t.capacity)/t.consumption) * 100;
}
