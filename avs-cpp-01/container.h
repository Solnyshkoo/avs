//
// Created by Ksenia Petrova on 01.10.2021.
//

#ifndef AVS_CPP_01_CONTAINER_H
#define AVS_CPP_01_CONTAINER_H

#include "vehicle.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
struct container {
    enum {max_len = 10000}; // максимальная длина
    int len; // текущая длина
    vehicle *cont[max_len];
};

// Инициализация контейнера
void Init(container &c);

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c);

// Ввод содержимого контейнера из указанного потока
void In(container &c, FILE * fr, size_t st_size);

// Случайный ввод содержимого контейнера
void InRnd(container &c, int size);

// Вывод содержимого контейнера в указанный поток
void Out(container &c, FILE * fp);

void ShakerSort(container & c);

#endif //AVS_CPP_01_CONTAINER_H
