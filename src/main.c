#include <stdio.h>
#include <string.h>
#include "../include/dish.h"
#include "../include/fridge.h"
#include "../include/input.h"
#include "../include/deviation.h"

int main(){
    dish_list* fridge = NULL;
    int indicator = 0;
    int temp_e_value;
    int temp_cal;
    int temp_proteins;
    int temp_fats;
    int temp_carbohydrates;
    int temp_sugar;
    int temp_vit_A;
    int temp_vit_D;
    int temp_vit_E;
    int temp_vit_K;
    while(indicator != -1){
        printf("Введите название имеющегося продукта, если больше продуктов нет, то оставьте поле пустым \n");
        char *temp_name = input_string();
        if (temp_name == NULL) {
            indicator = -1;
            break;
        }
        else {
            printf("Введите параметр продукта: энергетическая ценность. \n");
            temp_e_value = input_int();
            if(temp_e_value == 0){
                printf("Некорректное значение. Попробуйте ввести продукт заново. \n");
                continue;
            }
            printf("Введите параметр продукта: количество калорий. \n");
            temp_cal = input_int();
            if(temp_cal == 0){
                printf("Некорректное значение. Попробуйте ввести продукт заново. \n");
                continue;
            }
            printf("Введите параметр продукта: белки. \n");
            temp_proteins = input_int();
            if(temp_proteins == 0){
                printf("Некорректное значение. Попробуйте ввести продукт заново. \n");
                continue;
            }
            printf("Введите параметр продукта: жиры. \n");
            temp_fats = input_int();
            if(temp_fats == 0){
                printf("Некорректное значение. Попробуйте ввести продукт заново. \n");
                continue;
            }
            printf("Введите параметр продукта: углеводы. \n");
            temp_carbohydrates = input_int();
            if(temp_carbohydrates == 0){
                printf("Некорректное значение. Попробуйте ввести продукт заново. \n");
                continue;
            }
            printf("Введите параметр продукта: сахар. \n");
            temp_sugar = input_int();
            if(temp_sugar == 0){
                printf("Некорректное значение. Попробуйте ввести продукт заново. \n");
                continue;
            }
            printf("Введите параметр продукта: Витамин А. 1, если есть, 0 или пустая строка если нет. \n");
            temp_vit_A = input_int();
            printf("Введите параметр продукта: Витамин D. 1, если есть, 0 или пустая строка если нет. \n");
            temp_vit_D = input_int();
            printf("Введите параметр продукта: Витамин E. 1, если есть, 0 или пустая строка если нет. \n");
            temp_vit_E = input_int();
            printf("Введите параметр продукта: Витамин K. 1, если есть. \n");
            temp_vit_K = input_int();
        }
        dish avail = {temp_name, temp_e_value, temp_cal, temp_proteins,temp_fats, temp_carbohydrates, temp_sugar,temp_vit_A,temp_vit_D,temp_vit_E,temp_vit_K};
        if(push(&fridge, avail)==false){
            printf("Не получилось добавить продукт, попробуйте еще раз. \n");
        };
    }
    printf("Теперь введите необходимые параметры для приема пищи. \n");
    printf("Введите параметр продукта: энергетическая ценность. Оставьте поле пустым, если неизвестно. \n");
    temp_e_value = input_int();
    printf("Введите параметр продукта: количество калорий. Оставьте поле пустым, если неизвестно. \n");
    temp_cal = input_int();
    printf("Введите параметр продукта: белки. Оставьте поле пустым, если неизвестно. \n");
    temp_proteins = input_int();
    printf("Введите параметр продукта: жиры. Оставьте поле пустым, если неизвестно. \n");
    temp_fats = input_int();
    printf("Введите параметр продукта: углеводы. Оставьте поле пустым, если неизвестно. \n");
    temp_carbohydrates = input_int();
    printf("Введите параметр продукта: сахар. Оставьте поле пустым, если неизвестно. \n");
    temp_sugar = input_int();
    printf("Введите параметр продукта: Витамин А. 1, если есть, 0, если нет. \n");
    temp_vit_A = input_int();
    printf("Введите параметр продукта: Витамин D. 1, если есть, 0, если нет. \n");
    temp_vit_D = input_int();
    printf("Введите параметр продукта: Витамин E. 1, если есть, 0, если нет. \n");
    temp_vit_E = input_int();
    printf("Введите параметр продукта: Витамин K. 1, если есть, 0, если нет. \n");
    temp_vit_K = input_int();
    dish target = {"target", temp_e_value, temp_cal, temp_proteins,temp_fats, temp_carbohydrates, temp_sugar,temp_vit_A,temp_vit_D,temp_vit_E,temp_vit_K};
    if(fridge != NULL) {
        char *result = find(target, fridge);
        printf("%s", result);
        del(fridge);
    }
    else{
        printf("У вас в холодильнике нет продуктов! Вам нечего есть! \n");
    }
    return 0;
}