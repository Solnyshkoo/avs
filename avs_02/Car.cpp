#include "Car.h"

void Car::out(FILE * fp) {
    fprintf(fp, "It is Car: Fuel capacity = %d (litres), ", capacity);
    fprintf(fp, "Fuel consumption = %f (100km), ", consumption);
    fprintf(fp, "Maximum speed = %d  (km/h). ", max_speed);
    fprintf(fp, "Maximum distance = %f (km)\n", distance());
}

Car::Car(int input[4]) {
    capacity = input[1];
    consumption = input[2];
    max_speed = static_cast<short>(input[3]);
}

Car::Car() {
    consumption = static_cast<double> (rand() % 10 + 3) + static_cast<double> (rand() % 1000 + 10) / 1000.0;
    capacity = rand() % 40 + 30;
    max_speed = rand() % 100 + 60;
};

double Car::distance() {
    return (static_cast<double>(capacity)/consumption) * 100;
}



