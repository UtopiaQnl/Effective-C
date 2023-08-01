#define bad_abs(x) (x >= 0 ? x : -x)


int func(int i)
{
    return bad_abs(i++);  // i++ - побочный эффект, т.е. инструкция которая меняет окружение
    // нужно избегать побочных эффектов в аргументах небезопасных макросов
}