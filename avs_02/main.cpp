#include <iostream>
#include "Container.h"
#include <time.h>
#include <stdlib.h>

void errorMsg() {
    std::cout << "Wrong amount of arguments!\n" << "Follow the instruction:\n\n";
    std::cout << "Command args:\n";
    std::cout << "-f / -n (whether read from file or create random)\n";
    std::cout << "filename1.txt (file from which Vehicles will be read if -f) OR number of Vehicles to randomly create\n";
    std::cout << "filename2.txt (file in which container BEFORE sort will be written)\n";
    std::cout << "filename3.txt (file in which container AFTER sort will be written)\n\n";

    std::cout << "Example:\n";
    std::cout << "./avs_02 -f input.txt before_sort.txt after_sort.txt\n";
    std::cout << "Or\n";
    std::cout << "./ans_02 -n 100 before_sort.txt after_sort.txt\n";
}


int main(int argc, char* argv[]) {

    std::cout << "Program started" << "\n";

    if (argc != 5) {
        errorMsg();
        return 1;
    }

    if (!strcmp(argv[1], "-f")) {
        std::cout << "Reading from file " << argv[2] << "...\n";
        Container c (argv[2]);

        std::cout << "Container created..." << "\n";
        c.printOut(argv[3]);
        std::cout << "Container successfully written to file " << argv[3] << "...\n";
        std::cout << "Sorting container using ShakerSort...\n";
        c.shakerSort();

        std::cout << "Container sorted. Writing results to file " << argv[4] << "...\n";
        c.printOut(argv[4]);
    } else if (!strcmp(argv[1], "-n")) {
        std::cout << "";
        srand(time(nullptr));
        Container c(atoi(argv[2]));

        std::cout << "Container with " << atoi(argv[2]) << " vehicles created..." << "\n";
        c.printOut(argv[3]);
        std::cout << "Container successfully written to file " << argv[3] << "...\n";
        std::cout << "Sorting container using ShakerSort...\n";
        c.shakerSort();

        std::cout << "Container sorted. Writing results to file " << argv[4] << "...\n";
        c.printOut(argv[4]);
    }

    std::cout << "Finished running." << "\n";

    return 0;
}
