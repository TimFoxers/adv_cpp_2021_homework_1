#include "../include/input.h"

char input_char() {
    char c = '\0';
    int result = 0;
    do {
        result = scanf("%c", &c);
    } while (result != 1);
    return c;
}

char *input_string() {
    char *string = NULL;
    size_t size = 0;
    size_t capacity = 0;
    char c = '\0';
    while (c = input_char(), c != EOF && c != '\n') {
        if (size + 1 >= capacity) {
            size_t new_capacity = !capacity ? 1 : capacity * 2;
            char *tmp = (char *)malloc((new_capacity + 1) * sizeof(char));
            if (!tmp) {
                if (string) {
                    free(string);
                }
                return NULL;
            }
            if (string) {
                tmp = strcpy(tmp, string);
                free(string);
            }
            string = tmp;
            capacity = new_capacity;
        }
        string[size] = c;
        string[size + 1] = '\0';
        ++size;
    }
    return string;
}

int input_int() {
    char c = '\0';
    int result = 0;
    while (c = input_char(), c != EOF && c != '\n') {
        if (!(c >= '0' && c <= '9')) {
            char *buf = input_string(); /* Read to the end of the string */
            if (buf) {
                free(buf);
            }
            return 0;
        }
        result = result * 10 + c - '0';
    }
    return result;
}