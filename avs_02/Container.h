#ifndef AVS_02_CONTAINER_H
#define AVS_02_CONTAINER_H

#include "Vehicle.h"
#include <sys/stat.h>

class Container {
public:
    Container();

    ~Container();

    // Reading from file
    Container(char* filename);

    // Random container with given size
    Container(size_t amount);

    // Printing container to given file
    void printOut(char* filename);

    // Sorting
    void shakerSort();

private:
    Vehicle* memory_ [10000] {};
    size_t amount_ = 0;
};


#endif //AVS_02_CONTAINER_H
