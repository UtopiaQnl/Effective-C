#include <stdlib.h>
#include <string.h>
#include <uchar.h>
#include <wchar.h>
#include <wctype.h>

int main(void)
{
    setlocale(LC_ALL, "");
    char c = 0xFF;
    if (c == EOF) puts("End of file");

    if (isdigit((uint8_t)c)) {
        puts("c is a digit");
    }

    size_t size_char16_t = sizeof(char16_t);
    size_t size_char32_t = sizeof(char32_t);

    size_t len_empty_char32 = sizeof(U"");  // 4
    size_t len_a_char32 = sizeof(U"a");  // 8

    size_t len_str_char32 = sizeof(U"Ab");  // 8 + 4
    size_t len_str2_char32 = sizeof(U"sMoj");  // 8 + n - 1

    size_t len_empty_char16 = sizeof(u"");  // 2
    size_t len_a_char16 = sizeof(u"a");  // 4

    size_t len_str_char16 = sizeof(u"Ab");  // 4 + 2
    size_t len_str2_char16 = sizeof(u"sMoj");  // 4 + n - 1

    // char k = 'ё';  // Error
    wchar_t k2 = L'ё';
    char16_t k3 = u'ё';
    char32_t k4 = U'🍌';

    char buf[MB_LEN_MAX + 1] = {0};
    mbstate_t ps;
    memset(&ps, 0, sizeof(ps));
    c32rtomb(buf, k, &ps);

    printf("Ё = %s\n", buf);

    putwchar(k2);
    putchar('\n');
    putwchar(k3);
    putchar('\n');
    putwchar(k4);
    putchar('\n');

    // typedef int wchar_t;
    WCHAR_MAX;
    INT_MAX;
    WCHAR_MIN;
    INT_MIN;
    // wchar_t c = 'ÿ';
    // wprintf("%", c);
    wprintf(L"%ls\n", L"ÿ");


    return EXIT_SUCCESS;
}
