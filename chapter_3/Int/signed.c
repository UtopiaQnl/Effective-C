#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define Abs(i) ((i) < 0 ? -(i) : (i))
#define AbsM(i, flag) ((i) >= 0 ? (i) : ((i) == (flag) ? (flag) : -(i)))
#define newl puts("")

void print(const char *restrict line);

int abs(const int i) {
    return (i >= 0) ? i : -(unsigned)i;
}

int32_t abs_t(const int32_t i) {
    return (i >= 0) ? i : -(uint32_t)i;
}

int main(void) {
    printf("SCHAR_MIN = %d\t", SCHAR_MIN);
    printf("SCHAR_MAX = %d\n", SCHAR_MAX);
    printf("int8_t min = %" PRId8 "\t", INT8_MIN);
    printf("int8_t max = %" PRId8 "\n", INT8_MAX);

    puts("");

    printf("SHRT_MIN = %d\t", SHRT_MIN);
    printf("SHRT_MAX = %d\n", SHRT_MAX);
    printf("int16_t min = %" PRId16 "\t", INT16_MIN);
    printf("int16_t max = %" PRId16 "\n", INT16_MAX);

    puts("");

    printf("INT_MIN = %d\t\t", INT_MIN);
    printf("INT_MAX = %d\n", INT_MAX);
    printf("int32_t min = %" PRId32 "\t", INT32_MIN);
    printf("int32_t max = %" PRId32 "\n", INT32_MAX);

    puts("");

    printf("LONG_MIN = %ld\t\t", LONG_MIN);
    printf("LONG_MAX = %ld\n", LONG_MAX);
    printf("int64_t min = %" PRId64 "\t", INT64_MIN);
    printf("int64_t max = %" PRId64 "\n", INT64_MAX);

    puts("");

    printf("LLONG_MIN = %lld\t\t", LLONG_MIN);
    printf("LLONG_MAX = %lld\n", LLONG_MAX);
    printf("int64_t min = %" PRId64 "\t\t", INT64_MIN);
    printf("int64_t max = %" PRId64 "\n", INT64_MAX);

    puts("");

    printf("ULLONG_MAX = %llu\n", ULLONG_MAX);
    printf("uint64_t max = %" PRIu64 "\n", UINT64_MAX);

    newl;

    signed int si = -25;
    printf("si = %d\n", si);
    signed int abs_si = Abs(si);
    printf("abs_si = %d\n", abs_si);
    newl;

    int32_t si2 = -255;
    printf("si2 = %" PRId32 "\n", si2);
    int32_t abs_si2 = Abs(si2);
    printf("abs_si2 = %" PRId32 "\n", abs_si2);

    newl;

    signed int sin = INT_MIN;
    printf("sin = %d\n", sin);
    signed int abs_sin = Abs(sin);  // неопределённое поведение
    printf("abs_sin = %d\n", abs_sin);

    newl;

    int32_t sin2 = INT32_MIN;
    printf("sin2 = %" PRId32 "\n", sin2);
    int32_t abs_sin2 = Abs(sin2);  // неопределённое поведение
    printf("abs_sin2 = %" PRId32 "\n", abs_sin2);

    newl;

    printf("-INT_MIN = %d\n", -INT_MIN);
    printf("-INT32_MIN = %" PRId32 "\n", -INT32_MIN);

    // Макрос корректно возвращает модуль числа –25. Пока все хорошо.
    // Но проблема в том, что результат смены знака для самого маленького
    // отрицательного значения заданного типа в дополнительном коде не мо-
    // жет быть представлен этим типом, поэтому такое применение функции
    // Abs приводит к переполнению знакового целого.
    newl;

    signed int si3 = -25;  // попробуйте INT_MIN, чтобы спровоцировать проблемный случай
    signed int abs_si3 = AbsM(si3, INT_MIN);
    if (abs_si3 == INT_MIN)
        puts("особый случай");
    else
        printf("abs_si3 = %d\n", abs_si);  // выводит 25

    newl;

    int32_t si4 = INT32_MIN;
    int32_t abs_si4 = AbsM(si4, INT32_MIN);
    if (abs_si4 == INT32_MIN)
        puts("особый случай для int32_t");
    else
        printf("abs_si4 = %d" PRId32 "\n", abs_si4);

    newl;

    signed int a = INT_MIN;
    printf("a = %d\n", a);
    printf("-(unsigned)a = %u\n", -(unsigned)a);
    printf("abs(a) = %u\n", abs(a));

    newl;

    int32_t b = INT32_MIN;
    printf("b = %" PRId32 "\n", b);
    printf("-(uint32_t) = %" PRIu32 "\n", -(uint32_t)b);
    printf("abs_t(b) = %" PRIu32 "\n", abs_t(b));

    printf("0x%x = %d = %%i - %i\n", 0XFFF, 0xfff, 0xFFF);
    printf("o%o = %d = %%i - %i\n", 0777, 0777, 0777);

    return EXIT_SUCCESS;
}

void print(const char *restrict line) {
    printf("%s\n", line);
}
