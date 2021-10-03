//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <fstream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <cstring>
#include <sys/stat.h>

#include "container.h"

void errMessage1() {
    printf( "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01\n"
            "  Or:\n"
            "     command -n number outfile01\n");
}

void errMessage2() {
    printf( "incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01\n"
            "  Or:\n"
            "     command -n number outfile01\n");
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        errMessage1();
        return 1;
    }

    FILE * fp = fopen(argv[3], "w");
    printf( "Start\n");
    container c;
    Init(c);

    if (!strcmp(argv[1], "-f")) {

        FILE * fr = fopen(argv[2], "r");

        struct stat sb;

        if (stat(argv[2], &sb) == -1) {
            perror("stat");
            exit(EXIT_FAILURE);
        }

        In(c, fr, sb.st_size);
    }

    else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("incorrect number of figures");
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        InRnd(c, size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    ShakerSort(c);
    Out(c, fp);

    Clear(c);
    printf("Stop\n");
    return 0;
}
