//
// Created by Ksenia Petrova on 01.10.2021.
//

#include <sys/stat.h>
#include "container.h"
//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c) {
    for(int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void In (container &c, FILE * fr, size_t st_size) {

    char * file_contents = (char *)malloc(st_size);

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
            c.cont[c.len] = In(inputs);
            c.len++;
        }
        ++counter;
    }
    free(file_contents);
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRnd(container &c, int size) {
    while(c.len < size) {
        if((c.cont[c.len] = InRnd()) != nullptr) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(container &c, FILE* fp) {
    fprintf(fp, "Container contains %d elements\n", c.len);
    for(int i = 0; i < c.len; i++) {
        fprintf(fp, "\n%d: ", i);
        Out(*(c.cont[i]), fp);
    }
}

void ShakerSort(container & c) {
    bool sorted = false;
    int start = 0;
    int end = c.len - 1;

    while (!sorted) {
        sorted = true;
        for (int i = start; i < end; ++i) {
            if (Distance(*(c.cont[i])) > Distance(*c.cont[i + 1])) {
                // С тяжелым сердцем пришлось убрать std::swap, потому что в C такой функции нет:(
                // Знаю, что из-за этого появляется лишнее копирование - но что поделать
                vehicle temp = *(c.cont[i]);
                *(c.cont[i]) = *(c.cont[i + 1]);
                *(c.cont[i + 1]) = temp;

                sorted = false;
            }
        }
        if (sorted) {
            break;
        }

        end--;
        sorted = true;

        for (int i = end - 1; i >= start; --i) {
            if (Distance(*(c.cont[i + 1])) < Distance(*c.cont[i])) {
                vehicle temp = *(c.cont[i]);
                *(c.cont[i]) = *(c.cont[i + 1]);
                *(c.cont[i + 1]) = temp;

                sorted = false;
            }
        }
        start++;
    }
}

