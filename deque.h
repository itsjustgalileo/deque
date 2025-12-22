#ifndef DEQUE_H_
#define DEQUE_H_ 1

/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif

    typedef struct Deque Deque;

    extern Deque *deque_create(void);
    extern void deque_destroy(Deque *deque);

    extern bool deque_push_back(Deque *deque, void *data);
    extern bool deque_push_front(Deque *deque, void *data);

    extern bool deque_pop_back(Deque *deque, void **out);
    extern bool deque_pop_front(Deque *deque, void **out);

    extern bool deque_remove(Deque *deque, void *elem);
    extern void deque_clear(Deque *deque);

    extern void *deque_head(const Deque *deque);
    extern void *deque_tail(const Deque *deque);

    extern size_t deque_size(const Deque *deque);
    extern bool deque_empty(const Deque *deque);
    
/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif

#endif /* !DEQUE_H_ */
