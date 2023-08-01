// Преобразует строковй аргумент arg в значение unsigned long long (uint64_t),
// на которое ссылается val
// Возвращает true, если преобразование аргументов было успешным,
// и false, если нет.
static bool convert_arg(const char *arg, uint64_t *val)
{
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
