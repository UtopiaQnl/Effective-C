#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record {
    char name[80];
    int32_t number;
} record;

struct INFO {
    uint16_t ID;
};

void init_record(record *restrict rec) {
    strcpy(rec->name, "Unkwon");
    rec->number = 0;
}

char *get_hello(void) {
    return "hello!";
}

void sum(int32_t a, int32_t b) {
    printf("sum a + b = %" PRId32 "\n", a + b);
}

void add(int32_t to, int32_t from) {
    printf("result %" PRId32 "\n", to + from);
}

void sub(int32_t to, int32_t from) {
    printf("result %" PRId32 "\n", to - from);
}

struct INFO get_null_info(void) {
    struct INFO ret;
    ret.ID = -1;
    return ret;
}
// Объявите массив с тремя указателями на функции и вызовите функцию,
// которая соответствует индексу, переданному в качестве аргумента.
int main(void) {
    void (*funcs[3])(int32_t, int32_t) = {sum, add, sub};

    int32_t a = 100;
    int32_t b = 54;
    for (size_t i = 0; i < 3; i++) {
        void (*func)(int32_t, int32_t) = funcs[i];
        func(a, b);
    }
    putchar('\n');

    struct INFO result = get_null_info();

    printf("result.ID = %" PRId16 "\n\n", result.ID);
    printf("get_hello() -> %s\n\n", get_hello());

    record new_record;
    init_record(&new_record);

    puts("NEW RECORD:");
    printf("Number = %" PRId32 "\nName = %s\n", new_record.number, new_record.name);

    return EXIT_SUCCESS;
}
