#include "Container.h"
#include "Car.h"
#include "Bus.h"
#include "Truck.h"
#include <stdio.h>


Vehicle* initVehicle(int inputs[4]) {
    if (inputs[0] == 1) {
        return new Car(inputs);
    } else if (inputs[0] == 2) {
        return new Bus(inputs);
    } else if (inputs[0] == 3) {
        return new Truck(inputs);
    } else {
        return nullptr;
    }
}

Container::Container() = default;

Container::~Container() {
    for (size_t i = 0; i < amount_; ++i) {
        delete memory_[i];
    }
}

void Container::printOut(char *filename) {
    FILE * fp = fopen(filename, "w");

    fprintf(fp, "Container contains %d elements\n", static_cast<int>(amount_));
    for (size_t i = 0; i < amount_; i++) {
        fprintf(fp, "\n%d: ", static_cast<int>(i));
        (memory_[i]) -> out(fp);
    }

}

Container::Container(char* filename) {

    FILE * fr = fopen(filename, "r");

    struct stat sb;

    if (stat(filename, &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    char * file_contents = (char *)malloc(sb.st_size);

    int inputs[4];

    int counter = -1;

    while (fscanf(fr, "%[^\n ] ", file_contents) != EOF) {
        if (counter == -1) {
            ++counter;
            continue;
        } else {
            inputs[counter % 4] = atoi(file_contents);
        }
        if (counter % 4 == 3) {
            memory_[amount_] = initVehicle(inputs);
            amount_++;
        }
        ++counter;
    }
}

Vehicle* getRandomVehicle() {
    int i = rand() % 3 + 1;
    if (i == 1) {
        return new Car();
    } else if (i == 2) {
        return new Bus();
    } else {
        return new Truck();
    }
    return nullptr;
}

Container::Container(size_t amount) {
    while (amount_ < amount) {
        if ((memory_[amount_] = getRandomVehicle()) != nullptr) {
            amount_++;
        }
    }
}

void Container::shakerSort() {
    bool sorted = false;
    int start = 0;
    int end = static_cast<int>(amount_) - 1;

    while (!sorted) {
        sorted = true;
        for (int i = start; i < end; ++i) {
            if (memory_[i]->distance() > memory_[i + 1]->distance()) {
                std::swap(memory_[i], memory_[i + 1]);

                sorted = false;
            }
        }
        if (sorted) {
            break;
        }

        end--;
        sorted = true;

        for (int i = end - 1; i >= start; --i) {
            if (memory_[i + 1]->distance() < memory_[i]->distance()) {
                std::swap(memory_[i], memory_[i + 1]);
                sorted = false;
            }
        }
        start++;
    }
}
