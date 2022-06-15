#ifndef _CAR_H_
#define _CAR_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct Car{
    char model[21];
    uint8_t maxspeed;
    double price;
} Car;

double randouble(double min, double max);
uint8_t randuint(uint8_t min, uint8_t max);
char* name_generator(char* name);

int compModelASC(const void* car1, const void* car2);
int compModelDESC(const void* car1, const void* car2);
int compSpeedASC(const void* car1, const void* car2);
int compSpeedDESC(const void* car1, const void* car2);
int compPriceASC(const void* car1, const void* car2);
int compPriceDESC(const void* car1, const void* car2);

int (*getComparator(int n))(const void*, const void*);

#endif
