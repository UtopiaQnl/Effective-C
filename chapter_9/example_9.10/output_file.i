# 1 "foo.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 375 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "foo.c" 2
# 1 "./my.h" 1
# 2 "foo.c" 2

struct S {
    int x, y;
};

int main(void)
{

    struct S val = ATOMIC_VAR_INIT;
    return 0;
}
