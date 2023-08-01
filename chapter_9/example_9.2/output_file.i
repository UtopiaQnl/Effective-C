# 1 "foo.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 375 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "foo.c" 2
# 1 "./bar.h" 1
int func(void);
# 2 "foo.c" 2

int main(void)
{
    return func();
}
# 1 "func.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 375 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "func.c" 2
extern int func(void)
{
    return 0;
}
