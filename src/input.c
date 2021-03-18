#include "../include/input.h"

char input_char() {
    char c = '\0';
    int result;
    do {
        result = scanf("%c", &c);
    } while (result != 1);
    return c;
}

char *input_string() {
    char *string = NULL;
    size_t size = 0;
    size_t capacity = 1;
    char c;
    while (c = input_char(), c != EOF && c != '\n') {
        if (size + 1 >= capacity) {
            capacity *= 2;
            char *prev_string = (char *)malloc((capacity + 1) * sizeof(char));
            if (!prev_string) {
                if (string) {
                    free(string);
                }
                return NULL;
            }
            if (string) {
                prev_string = strcpy(prev_string, string);
                free(string);
            }
            string = prev_string;
        }
        string[size] = c;
        string[size + 1] = '\0';
        ++size;
    }
    return string;
}

int input_int() {
    char c;
    int result = 0;
    while (c = input_char(), c != EOF && c != '\n') {
        if (!(c >= '0' && c <= '9')) {
            char *buf = input_string();
            if (buf) {
                free(buf);
            }
            return 0;
        }
        result = result * 10 + c - '0';
    }
    return result;
}