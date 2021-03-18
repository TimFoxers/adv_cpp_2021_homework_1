//Так как идеально подходящего продукта обычно нет, мы можем только найти наименее неподходящий
#include "../include/deviation.h"

int deviation(dish applicant, dish desire){ //функция вычисления отклонения продукта от требований
    int result = 0;

    if(desire.cal != 0){
        result += abs(applicant.cal - desire.cal);
    }

    if(desire.e_value != 0){
        result += abs(applicant.e_value - desire.e_value);
    }

    if(desire.proteins != 0){
        result += abs(applicant.proteins - desire.proteins);
    }

    if(desire.fats != 0){
        result += abs(applicant.fats - desire.fats);
    }

    if(desire.carbohydrates != 0){
        result += abs(applicant.carbohydrates - desire.carbohydrates);
    }

    if(desire.sugar != 0){
        result += abs(applicant.sugar - desire.sugar);
    }

    if((desire.vit_A == 1)&&(applicant.vit_A == 0)){
        result += 10;
    }

    if((desire.vit_D == 1)&&(applicant.vit_D == 0)){
        result += 10;
    }

    if((desire.vit_E == 1)&&(applicant.vit_E == 0)){
        result += 10;
    }

    if((desire.vit_K == 1)&&(applicant.vit_K == 0)){
        result += 10;
    }

    return result;
}

char *find(dish target, dish_list *fridge){
    int min = deviation(fridge->current, target);
    char* min_name = fridge->current.name;
    dish_list *node = fridge->next;

    if(node == NULL) {
        return min_name;
    }

    while (node->next != NULL) {
        int temp = deviation(target, node->current);

        if (temp < min) {
            min = temp;
            min_name = node->current.name;
        }

        node = node->next;
    }
    return min_name;
}