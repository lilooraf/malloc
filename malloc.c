/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** malloc
*/

#include "my_malloc.h"
#include <math.h>

t_block *HEAP_START = NULL;
t_block *PREV_BLOCK = NULL;

void *split(t_block *a, t_block *new, size_t size)
{
    t_block *next;

    if (a->size > size + sizeof(t_block) + 4) {
        new = a->ptr + size;
        new->size = a->size - (size + sizeof(t_block));
        new->free = 1;
        new->ptr = a->ptr + size + sizeof(t_block);
        new->first_free = NULL;
        new->prev = a;
        next = new->ptr + new->size;
        if ((size_t)next < (size_t)sbrk(0))
            next->prev = new;
        a->free = 0;
        a->size = size;
        return a->ptr;
    } else {
        return NULL;
    }
}

void *same_size(t_block *a, size_t size)
{
    if (a->size == size) {
        HEAP_START->free_nb -= 1;
        a->free = 0;
        return a->ptr;
    } else {
        return NULL;
    }
}

void *find_free(size_t size, t_block *new)
{
    void *s;
    t_block *a = HEAP_START;
    void *end = sbrk(0);

    if (a->free_nb <= 0)
        return NULL;
    a = (a->first_free != NULL) ? a->first_free : a;
    for (;(long)a < (long)end; a = a->size + a->ptr) {
        if (!a->free)
            continue;
        s = same_size(a, size);
        if (s != NULL)
            return s;
        s = split(a, new, size);
        if (s != NULL)
            return s;
    }
    return NULL;
}

void *new_node(void *new_ptr, t_block *new, size_t size)
{
    for (size_t i = size / ((size_t)pow(2, 22)); i > 0; i--) {
        if (new_ptr == NULL)
            new_ptr = sbrk((size_t)pow(2, 22));
        else
            sbrk((size_t)pow(2, 22));
    }
    if (new_ptr == NULL)
        new_ptr = sbrk(sizeof(t_block) + size);
    if (new_ptr == (void *) -1)
        return NULL;
    new = new_ptr;
    new->free = 0;
    new->first_free = NULL;
    new->size = size;
    new->ptr = new_ptr + sizeof(t_block);
    new->prev = PREV_BLOCK;
    PREV_BLOCK = new;
    return new->ptr;
}

void *malloc(size_t size)
{
    t_block *new = NULL;
    void *s = NULL;
    void *new_ptr = NULL;

    if (size <= 0)
        return NULL;
    for (float mod = 1; mod != 0; mod = (++size + sizeof(t_block)) % 1024);
    if (HEAP_START == NULL) {
        HEAP_START = sbrk(0);
    } else {
        s = find_free(size, new);
        if (s != NULL) {
            PREV_BLOCK = s - sizeof(t_block);
            return s;
        }
    }
    return new_node(new_ptr, new, size);
}