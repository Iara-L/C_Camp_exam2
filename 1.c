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

int main(){
    srand(time(NULL));
    int option;
    Car cars[10];

    for(int i = 0; i < 10; i++){
        name_generator(cars[i].model);
        cars[i].maxspeed = randuint(100, 300);
        cars[i].price = randouble(1000.00, 100000.00);
    }

    scanf("%d", &option);
    qsort(cars, 10, sizeof(cars[0]), getComparator(option));

    for(int i = 0; i < 10; i++){
        printf("%10s\t", cars[i].model);
        printf("%2u\t", cars[i].maxspeed);
        printf("%4.2lf\n", cars[i].price);
    }

    return 0;
}

double randouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

uint8_t randuint(uint8_t min, uint8_t max){
    return min + rand() % (max - min + 1);
}

char* name_generator(char* name){
    int index = 0;

    name[index++] = randuint('A', 'Z');

    for(int i = 1; i < randuint(4, 10); i++){
        name[index++] = randuint('a', 'z');
    }
    name[index++] = '\0';
}

int compModelASC(const void* car1, const void* car2){
    Car* c1 = (Car*)car1;
    Car* c2 = (Car*)car2;
    return strcmp(c1->model, c2->model);
}

int compModelDESC(const void* car1, const void* car2){
    Car* c1 = (Car*)car1;
    Car* c2 = (Car*)car2;
    return strcmp(c2->model, c1->model);
}

int compSpeedASC(const void* car1, const void* car2){
    Car* c1 = (Car*)car1;
    Car* c2 = (Car*)car2;
    return strcmp(c1->maxspeed, c2->maxspeed);
}

int compSpeedDESC(const void* car1, const void* car2){
    Car* c1 = (Car*)car1;
    Car* c2 = (Car*)car2;
    return strcmp(c2->maxspeed, c1->maxspeed);
}

int compPriceASC(const void* car1, const void* car2){
    Car* c1 = (Car*)car1;
    Car* c2 = (Car*)car2;
    if(fabs(c1->price - c2->price) < 0.001){
        return 0;
    }else if(c1->price > c2->price){
        return 1;
    }
    return -1;
}

int compPriceDESC(const void* car1, const void* car2){
    Car* c1 = (Car*)car1;
    Car* c2 = (Car*)car2;
    if(fabs(c1->price - c2->price) < 0.001){
        return 0;
    }else if(c1->price < c2->price){
        return 1;
    }
    return -1;
}

int (*getComparator(int n))(const void*, const void*){
    switch (n)
    {
    case 1:
        return compModelASC;
        break;
    case 2:
        return compModelDESC;
        break;
    case 3:
        return compSpeedASC;
        break;
    case 4:
        return compSpeedDESC;
        break;
    case 5:
        return compPriceASC;
        break;
    case 6:
        return compPriceDESC;
        break;
    default:
        return NULL;
    }
}