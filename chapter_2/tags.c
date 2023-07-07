#include <stdint.h>
// Идентификатор s является тегом.

struct s {
    // --snip--
};

// Сам по себе тег не является именем типа, и его нельзя использовать для определения переменных.
// Вместо этого прееменные таких типов следует объявлять таким образом:
struct s v;   // экземпляр структуры s
struct s *p;  // указательная на на структуру s

// Названия объединений и перечислений — тоже теги, а не типы. Это значит, их недостаточно
// для объявления переменной. Например:

enum day { sun, mon, tue, wed, thu, fri, sat };
day today;          // ошибка
enum day tomorrow;  // правильно

// Теги структур, объединений и перечислений определяются в собственном пространстве имен, отдельно
// от обычных идентификаторов. Благодаря этому программа на C может иметь в одной области видимости
// тег и другой идентификатор, который выглядит точно так же:

enum status { ok, fail };  // перечисление
enum status status(void);  // функция

// Вы даже можете объявить объект s типа struct s:

struct s s;

// Это не самое лучшее решение, но в языке C оно является корректным. Теги
// структур можно считать именами типов и определять для них псевдонимы
// с помощью typedef. Например:

typedef struct another_s {
    int32_t x;
} t;

// Это будет работать всегда, кроме тех случаев, когда структура содержит указатель на саму себя:

struct tnode {
    int32_t count;
    struct tnode *left;
    struct tnode *right;
};

// Если опустить тег в первой строчке, то компилятору это может не понравиться, поскольку
// структура, упоминаемая в третьей и четвертой строчках, еще не объявлена или просто
// потому, что нигде не используется. Таким образом, вам не остается ничего другого, как
// объявить для данной структуры тег. Но вы также можете объявить typedef:

typedef struct node {
    int32_t count;
    struct node *left;
    struct node *right;
} node;