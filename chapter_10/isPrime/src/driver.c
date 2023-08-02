#include <assert.h>
#include <errno.h>
#include <inttypes.h>
#include <limits.h>
#include <stdio.h>

#include "isprime.h"


// Преобразует строковй аргумент arg в значение unsigned long long (uint64_t),
// на которое ссылается val
// Возвращает true, если преобразование аргументов было успешным,
// и false, если нет.
static bool convert_arg(const char *arg, uint64_t *val);

static uint64_t *convert_command_line_args(int argc, const char *argv[], size_t *num_args);

static void print_help(void);


int main(int argc, char *argv[])
{
    size_t num_args;

    uint64_t *vals = convert_command_line_args(argc, (const char **)argv, &num_args);

    if (!vals) return EXIT_FAILURE;

    for (size_t i = 0; i < num_args; ++i) {
        printf("%" PRIu64 " is %s.\n", vals[i], is_prime(vals[i], 100) ? "probably prime" : "not prime");
    }
    free(vals);

    return EXIT_SUCCESS;
}


static void print_help(void)
{
    puts("primetest num1 [num2 num3 ... numN]\n");
    puts("Tests positive integers for primality. Supports testing");
    printf("%s [2-%" PRIuMAX "].\n", "numbers in the range", UINTMAX_MAX);
}


static bool convert_arg(const char *arg, uint64_t *val)
{
    // Простые числа принадлежат натуральному множеству числе, т.е. отрицательным числам тут не место (переполнение)
    if (arg[0] == '-') return false;

    char *end;
    // strtoull возвращает внутренний индикатор ошибки; очистите errno перед вызовом
    errno = 0;
    *val = strtoull(arg, &end, 10);

    // Отслеживаем ошибки, когда вызов возвращает контрольное значние
    // и устанавливает errno
    if ((*val == UINT64_MAX) && errno) return false;
    if (*val == 0 && errno) return false;
    if (end == arg) return false;

    // Если мы попали сюда, нам удалось преобразовать аргумент.
    // Но мы хотим допускать только значения больше 1, поэтому мы отбрасывает все значание <= 1
    if (*val <= 1) return false;
    return true;
}


static uint64_t *convert_command_line_args(int argc, const char *argv[], size_t *num_args)
{
    *num_args = 0;

    if (argc <= 1) {
        // Непредоставление никаких аргументов командной строки (первый аргумент - это имя исполняемой программы)
        print_help();
        return NULL;
    }

    // Мы знаем, какое максимальное количество аргументов мог бы передать пользователь,
    // поэтому выделяем массив, способный их вместить. Вычитаем оди, имя самой программы.
    // Если выделение оказывается неудачным, считаем это ошибкой преобразования
    // (можно вызвать free(NULL)).
    uint64_t *args = (uint64_t *)malloc(sizeof(uint64_t) * ((uint64_t)argc - 1));
    bool failed_conversion = (args == NULL);
    for (int i = 1; i < argc && !failed_conversion; ++i) {
        // Пытаемся преобразовать аргументы в целое число. Если его не удается преобразовать,
        // присваиваем failed_conversion значение true
        uint64_t one_arg;
        failed_conversion |= !convert_arg(argv[i], &one_arg);
        args[i - 1] = one_arg;
    }

    if (failed_conversion) {
        // Освобождаем массив, выводим справочный текст и выходим.
        free(args);
        print_help();
        return NULL;
    }

    *num_args = (size_t)argc - 1;
    return args;
}
