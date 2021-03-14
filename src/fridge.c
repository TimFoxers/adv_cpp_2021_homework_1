#include "../include/dish.h"
#include "../include/fridge.h"

bool push(dish_list** list, dish add) {
    dish_list* node = malloc(sizeof(dish_list));
    if(!node){
        return false;
    }
    node->current = add;
    node->next = *list;
    *list = node;
    return true;
}

void del(dish_list* list){
    if (list) {
        del(list->next);
        free(list);
    }
}