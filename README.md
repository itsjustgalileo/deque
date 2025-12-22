# DEQUE

---

## PRESENTATION

Double-ended queue (Deque) implementation in C99.

---

## PREREQUISITES

- C99 compiler.

---

## EXAMPLE

```c
#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

int main(void)
{
    Deque *d = deque_create();
    if (!d) return 1;

    int a = 1, b = 2, c = 3, dval = 4;

    deque_push_back(d, &a);   /* back: 1 */
    deque_push_back(d, &b);   /* back: 1 2 */
    deque_push_front(d, &c);  /* front: 3 1 2 */
    deque_push_front(d, &dval); /* front: 4 3 1 2 */

    while (!deque_empty(d)) {
        int *x = NULL;
        deque_pop_front(d, (void **)&x);
        printf("%d\n", *x);
    }

    deque_destroy(d);
    return 0;
}
```
