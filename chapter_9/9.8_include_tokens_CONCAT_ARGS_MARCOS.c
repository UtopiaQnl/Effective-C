#define CONCAT(x, y) x##_##y

int CONCAT(foo, bar) = 12;
