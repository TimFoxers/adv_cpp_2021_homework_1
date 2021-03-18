#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "dish.h"

#ifndef ADVCPP2021HOMEWORK1_FRIDGE_H
#define ADVCPP2021HOMEWORK1_FRIDGE_H

typedef struct dish_list {
    dish current;
    struct dish_list* next;
} dish_list;

bool push(dish_list** list, dish add);
void del(dish_list* list);

#endif //ADVCPP2021HOMEWORK1_FRIDGE_H
