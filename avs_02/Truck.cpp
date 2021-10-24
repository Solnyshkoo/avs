#include "Truck.h"

Truck::Truck(int inputs[4]) {
    capacity = inputs[1];
    consumption = inputs[2];
    lifting = inputs[3];
}

void Truck::out(FILE * fp) {
    fprintf(fp, "It is Truck: Fuel capacity = %d (litres), ", capacity);
    fprintf(fp, "Fuel consumption = %f (100km), ", consumption);
    fprintf(fp, "Lifting capacity = %d  (kg). ", lifting);
    fprintf(fp, "Maximum distance = %f (km)\n", distance());
}

Truck::Truck() {
    consumption = static_cast<double> (rand() % 10 + 3) + static_cast<double> (rand() % 1000 + 10) / 1000.0;
    capacity = rand() % 40 + 30;
    lifting = rand() % 3000 + 1500;
}


double Truck::distance() {
    return (static_cast<double>(capacity)/consumption) * 100;
}