#ifndef DEQUE_H_
#define DEQUE_H_

/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif

    /**
     * @brief
     */
    typedef struct Deque Deque;

    /**
     * @brief
     *
     * @return
     */
    extern Deque *deque_create(void);

    /**
     * @brief
     *
     * @param[in]
     */
    extern void deque_destroy(Deque *deque);

    /**
     * @brief
     *
     * @param[in]
     * @param[in]
     *
     * @return
     */
    extern bool deque_push_back(Deque *deque, void *data);

    /**
     * @brief
     *
     * @param[in]
     * @param[in]
     *
     * @return
     */
    extern bool deque_push_front(Deque *deque, void *data);

    /**
     * @brief
     *
     * @param[in]
     * @param[out]
     *
     * @return
     */
    extern bool deque_pop_back(Deque *deque, void **out);

    /**
     * @brief
     *
     * @param[in]
     * @param[out]
     *
     * @return
     */
    extern bool deque_pop_front(Deque *deque, void **out);

    /**
     * @brief
     *
     * @param[in]
     * @param[in]
     *
     * @return
     */
    extern bool deque_remove(Deque *deque, void *elem);

    /**
     * @brief
     *
     * @param[in]
     *
     * @return
     */
    extern void deque_clear(Deque *deque);

    /**
     * @brief
     *
     * @param[in]
     *
     * @return
     */
    extern void *deque_head(const Deque *deque);

    /**
     * @brief
     *
     * @param[in]
     *
     * @return
     */
    extern void *deque_tail(const Deque *deque);

    /**
     * @brief
     *
     * @param[in]
     *
     * @return
     */
    extern size_t deque_size(const Deque *deque);

    /**
     * @brief
     *
     * @param[in]
     *
     * @return
     */
    extern bool deque_empty(const Deque *deque);

/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif

#endif /* !DEQUE_H_ */
