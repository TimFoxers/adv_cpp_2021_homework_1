#include <gtest/gtest.h>
#include <iostream>

extern "C" {
#include "dish.h"
#include "deviation.h"
#include "fridge.h"
}

char apps[] = "app";
char dess[] = "des";
char ents[] = "ent";
char rights[] = "right";
char copy[] = "copy";
char copy_right[] = "copy_right";
char gut[] = "gut";

const dish app = {apps, 23, 23, 6,12, 224, 12,1,1,1,0};
const dish app2 = {apps, 24, 21, 3,10, 221, 5,1,0,0,1};
const dish des = {dess, 21, 23, 6,12, 234, 12,1,1,1,1};
const dish des2 = {ents, 23, 23, 6,12, 234, 12,0,0,0,1};
const dish des3 = {rights, 22, 23, 6,12, 224, 12,1,1,1,1};
const dish des4 = {copy, 22, 23, 6,12, 224, 12,1,1,1,1};
const dish des5 = {copy_right, 22, 23, 6,12, 224, 12,1,1,1,0};
const dish des6 = {copy, 0, 0, 0,0, 0, 0,1,1,1,0};
const dish diet = {gut, 0, 0, 0,0, 0, 0,0,0,0,0};

TEST(deviation, values_1) {
    EXPECT_EQ(deviation(app, des), 22);
}

TEST(deviation, values_3) {
    EXPECT_EQ(deviation(des2, app), 40);
}

TEST(deviation, values_equality) {
    EXPECT_EQ(deviation(des3, des4), 0);
}

TEST(deviation, values_vitamins_lack) {
    EXPECT_EQ(deviation(des4, des5), 0);
}

TEST(deviation, no_applicant_values) {
    EXPECT_EQ(deviation(des5, des6), 0);
}

TEST(deviation, values_4) {
    EXPECT_EQ(deviation(app, app2), 28);
}

TEST(deviation, values_no) {
    EXPECT_EQ(deviation(des5, diet), 0);
}

TEST(deviation, values_5) {
    EXPECT_EQ(deviation(des4, des6), 0);
}

TEST(fridge, initialization_0) {
    dish_list* fridge = NULL;
    push(&fridge, des5);
    EXPECT_EQ(fridge->current.carbohydrates, 224);
    del(fridge);
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

TEST(fridge, initialization_3) {
    dish_list* fridge = NULL;
    push(&fridge, des);
    push(&fridge, des2);
    push(&fridge, des3);
    EXPECT_EQ(fridge->next->next->current.proteins, 6);
    del(fridge);
}

TEST(find, values_1) {
    dish_list* fridge = NULL;
    push(&fridge, des);
    push(&fridge, des2);
    push(&fridge, des3);
    char *result = find(app, fridge);
    EXPECT_EQ(result, rights);
    del(fridge);
}

TEST(find, values_2) {
    dish_list* fridge = NULL;
    push(&fridge, des);
    char *result = find(app, fridge);
    EXPECT_EQ(result, dess);
    del(fridge);
}

TEST(find, values_3) {
    dish_list* fridge = NULL;
    push(&fridge, des);
    push(&fridge, des3);
    push(&fridge, des2);
    char *result = find(app, fridge);
    EXPECT_EQ(result, rights);
    del(fridge);
}

TEST(find, no_difference) {
    dish_list* fridge = NULL;
    push(&fridge, app);
    push(&fridge, des);
    push(&fridge, des4);
    char *result = find(diet, fridge);
    EXPECT_EQ(result, copy);
    del(fridge);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

