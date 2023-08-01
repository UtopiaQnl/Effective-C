# 1 "file.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 375 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "file.c" 2
enum Names {

# 1 "./header.h" 1
first,
second,
third,
# 4 "file.c" 2

};

void func(enum Names Name)
{
    switch (Name) {

# 1 "./header.h" 1
case first:
case second:
case third:
# 12 "file.c" 2

    }
}
