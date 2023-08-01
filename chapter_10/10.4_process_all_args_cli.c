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
    uint64_t *args = (uint64_t *)malloc(sizeof(uint64_t) * (argc - 1));
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

    *num_args = argc - 1;
    return args;
}
