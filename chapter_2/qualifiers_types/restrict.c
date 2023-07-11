// restrict-квалифицированный указатель используется для поддержки
// оптимизации. Объекты, к которым обращаются косвенно через указатели,
// зачастую не удается оптимизировать должным образом из-за того, что
// на один и тот же объект теоретически могут ссылаться сразу несколько
// указателей. Это может затруднить оптимизацию, поскольку компилятор
// не знает, может ли модификация одного объекта привести к частичному
// изменению другого, который с виду никак с ним не связан.
#include <stdint.h>

/* Копирует n байт с учатка памяти, на который указывает q,
 * на участок, на который указывает p. */
void func(uint32_t n, int32_t *restrict p, int32_t *restrict q) {
    while (n-- > 0) {
        *p++ = *q++;
    }
}

// Поскольку p и q являются restrict-квалифицированными указателями,
// компилятор может исходить из того, что обращение к объекту через один
// из этих параметров не приведет к обращению через другой. Это предполо-
// жение основано исключительно на объявлениях параметров и не требует
// анализа тела функции. Использование указателей с квалификатором
// restrict делает код более эффективным, но, чтобы избежать неопределен-
// ного поведения, программист обязан обеспечить, чтобы участки памяти,
// на которые они ссылаются, не пересекались.