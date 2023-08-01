// Объектный макрос
#define FOO (1 + 1)

// Функциональный макрос (т.е. параметризированный)
#define BAR(x) (1 + (x))

int i = FOO;
int j = BAR(10);
int k = BAR(2 + 2);
int l = BAR(BAR(FOO) * (2 * 9) - FOO);
