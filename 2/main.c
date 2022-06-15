#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "car.h"

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
