#include <gtest/gtest.h>
#include <iostream>

extern "C" {
#include "dish.h"
#include "deviation.h"
}

char apps[] = "app";
char dess[] = "des";
char ents[] = "ent";
char rights[] = "right";

const dish app = {apps, 23, 23, 6,12, 224, 12,1,1,1,0};
const dish des = {dess, 21, 23, 6,12, 234, 12,1,1,1,1};
const dish des2 = {ents, 23, 23, 6,12, 234, 12,1,1,1,1};
const dish des3 = {rights, 22, 23, 6,12, 224, 12,1,1,1,0};

TEST(deviation, values_1) {
    EXPECT_EQ(deviation(app, des), 22);
}

TEST(fridge, initialization) {
    dish_list* fridge = NULL;
    push(&fridge, des);
    push(&fridge, des2);
    push(&fridge, des3);
    EXPECT_EQ(fridge->current.e_value, 22);
    del(fridge);
}

TEST(fridge, initialization_2) {
    dish_list* fridge = NULL;
    push(&fridge, des);
    push(&fridge, des2);
    push(&fridge, des3);
    EXPECT_EQ(fridge->next->current.e_value, 23);
    del(fridge);
}

TEST(find, values_1) {
    dish_list* fridge = NULL;
    push(&fridge, des);
    push(&fridge, des2);
    push(&fridge, des3);
    char *result = find(app, fridge);
    EXPECT_EQ(result, rights);
}

TEST(find, values_2) {
    dish_list* fridge = NULL;
    push(&fridge, des);
    char *result = find(app, fridge);
    EXPECT_EQ(result, dess);
}


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

