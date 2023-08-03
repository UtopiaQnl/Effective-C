#include <assert.h>
#include <string.h>
static const char prefix[] = "Error No: ";
#define ARRAYSIZE 14
char str[ARRAYSIZE];

// Убедимся в том, что str может вместить как минимум один
// дополнительный символ для кода ошибки
static_assert(sizeof(str) > sizeof(prefix), "str must be larger than prefix");

int main(void)
{
    strcpy(str, prefix);
    return 0;
}
