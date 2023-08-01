enum Names {
    #define NAME(X) X,
    #include "header.h"
    #undef NAME
};

void func(enum Names Name)
{
    switch (Name) {
        #define NAME(X) case X:
        #include "header.h"
        #undef NAME
    }
}
