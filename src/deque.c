#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "deque.h"

struct DequeNode {
    struct DequeNode *prev;
    struct DequeNode *next;
    void *data;
};

struct Deque {
    struct DequeNode *head;
    struct DequeNode *tail;
    size_t count;
};

Deque *deque_create(void)
{
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    if (NULL == deque) {
        return NULL;
    }

    deque->head = deque->tail = NULL;
    deque->count = 0;
    
    return deque;
}

void deque_destroy(Deque *deque)
{
    if (deque) {
        deque_clear(deque);
        free(deque);
    }

    return;
}

static struct DequeNode *deque_node_new(void *data)
{
    struct DequeNode *node = (struct DequeNode *)malloc(sizeof(struct DequeNode));

    if (NULL == node) {
        return NULL;
    }

    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

bool deque_push_back(Deque *deque, void *data)
{
    if (NULL == deque) {
        return false;
    }
    struct DequeNode *node = deque_node_new(data);
    if (NULL == node) {
        return false;
    }
    
    if (NULL == deque->head) {
        deque->head = deque->tail = node;        
    } else {
        deque->tail->next = node;
        node->prev = deque->tail;
        deque->tail = node;
    }
    
    ++deque->count;
    
    return true;
}

bool deque_push_front(Deque *deque, void *data)
{
    if (NULL == deque) {
        return false;
    }

    struct DequeNode *node = deque_node_new(data);
    if (NULL == node) {
        return false;
    }
    
    if (NULL == deque->head) {
        deque->head = deque->tail = node;
    } else {
        deque->head->prev = node;
        node->next = deque->head;
        deque->head = node;
    }

    ++deque->count;

    return true;
}

bool deque_pop_back(Deque *deque, void **out)
{
    if (NULL == deque) {
        return false;
    }

    if (deque->count == 0) {
        return false;
    }
        
    struct DequeNode *tmp = deque->tail;

    if (out) {        
        *out = tmp->data;    
    }
    
    if (deque->count == 1) {
        deque->head = deque->tail = NULL;
    } else {
        deque->tail = tmp->prev;
        deque->tail->next = NULL;
    }    
        
    free(tmp);
    --deque->count;
    
    return true;
}

bool deque_pop_front(Deque *deque, void **out)
{
    if (NULL == deque) {
        return false;
    }

    if (deque->count == 0) {
        return false;
    }
        
    struct DequeNode *tmp = deque->head;

    if (out) {        
        *out = tmp->data;    
    }
        
    if (deque->count == 1) {
        deque->head = deque->tail = NULL;
    } else {
        deque->head = tmp->next;
        deque->head->prev = NULL;
    }    
        
    free(tmp);
    --deque->count;
    
    return true;
}

bool deque_remove(Deque *deque, void *elem)
{
    if (NULL == deque) {
        return false;
    }

    struct DequeNode *node = deque->head;

    while (node) {
        if (node->data == elem) {

            if (node->prev) {
                node->prev->next = node->next;
            } else {
                deque->head = node->next;
            }

            if (node->next) {
                node->next->prev = node->prev;
            } else {
                deque->tail = node->prev;
            }

            free(node);
            --deque->count;
            return true;
        }

        node = node->next;
    }

    return false;
}

void deque_clear(Deque *deque)
{
    if (NULL == deque) {
        return;
    }

    struct DequeNode *node = deque->head;

    while (node) {
        struct DequeNode *next = node->next;
        free(node);
        node = next;
    }

    deque->head = NULL;
    deque->tail = NULL;
    deque->count = 0;
}

void *deque_head(const Deque *deque)
{
    if (NULL == deque || NULL == deque->head) {
        return NULL;
    }

    return deque->head->data;
}

void *deque_tail(const Deque *deque)
{
    if (NULL == deque || NULL == deque->tail) {
        return NULL;
    }

    return deque->tail->data;
}

size_t deque_size(const Deque *deque)
{
    if (NULL == deque) {
        return false;
    }
    return deque->count;
}

bool deque_empty(const Deque *deque)
{
    if (NULL == deque) {
        return false;
    }
    return (deque->count == 0);
}
