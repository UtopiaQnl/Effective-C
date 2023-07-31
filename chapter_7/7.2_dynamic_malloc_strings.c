#include <stdlib.h>
#include <string.h>
#include <wchar.h>

int main(void)
{
    // узкие строки 1.
    char str1[] = "Here comes the sun";
    char *str2 = malloc(strlen(str1) + 1);

    // широкие строки 2.
    wchar_t wstr1[] = L"Here comes the sun";
    wchar_t *wstr2 = malloc((wcslen(wstr1) + 1) * sizeof(wchar_t));

    // Для 1. чтобы определить размер для указателя на строку можно воспользоваться strlen(), чтобы узнать длину +1 для
    // нуль терминатора.

    // Для 2. нужно узнать длину wstr + 1 для нуль терминатора и тогда мы узнаем количество символов на которые должен
    // ссылаться указательно, но для выявления кол-во памяти это значение нужно умножить на кол-во байт, занимамых
    // wchar_t и тогда мы получим кол-во байт для хранения wchar_t строки.

    return EXIT_SUCCESS;
}
