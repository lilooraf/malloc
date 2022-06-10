/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** free
*/

#include "my_malloc.h"

extern t_block *HEAP_START;

void join(t_block *to_del)
{
    t_block *i;

    for (i = to_del->ptr + to_del->size; (size_t)i < (size_t)sbrk(0)
        && (i->free);
        i = i->size + i->ptr)
        to_del->size += i->size + sizeof(t_block);
    i = to_del->prev;
    for (t_block *next = to_del ; i != NULL &&
        (size_t)i > (size_t)HEAP_START && i->free;
        i = i->prev, next = i->ptr + i->size) {
        i->size = i->size + sizeof(t_block) + next->size;
    }
}

void free(void *ptr)
{
    t_block *first = HEAP_START;
    t_block *to_del;

    if (ptr == (void *)0)
        return;
    to_del = ptr - sizeof(t_block);
    join(to_del);
    HEAP_START->free_nb += 1;
    if (first->first_free == NULL)
        first->first_free = to_del;
    else if ((size_t)to_del < (size_t)first->first_free)
        first->first_free = to_del;
    to_del->free = 1;
}