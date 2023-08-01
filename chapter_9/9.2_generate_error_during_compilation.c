#if _STDC__ && __STDC_NO_THREADS__ != 1
#include <threads.h>
#elif POSIX_THREADS == 200809L
#include <pthread.h>
#else
int compile_error[-1];  // провоцируем ошибку компиляции
#endif
