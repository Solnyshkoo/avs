#include "Bus.h"

void Bus::out(FILE * fp) {
    fprintf(fp, "It is Bus: Fuel capacity = %d (litres), ", capacity);
    fprintf(fp, "Fuel consumption = %f (100km), ", consumption);
    fprintf(fp, "Maximum parson capacity = %d  (pers.). ", person_capacity);
    fprintf(fp, "Maximum distance = %f (km)\n", distance());
}

Bus::Bus(int input[4]) {
    capacity = input[1];
    consumption = input[2];
    person_capacity = static_cast<short>(input[3]);
}

Bus::Bus() {
    consumption = static_cast<double> (rand() % 10 + 3) + static_cast<double> (rand() % 1000 + 10) / 1000.0;
    capacity = rand() % 40 + 30;
    person_capacity = rand() % 90 + 45;
};

double Bus::distance() {
    return (static_cast<double>(capacity)/consumption) * 100;
}