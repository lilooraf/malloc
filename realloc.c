/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** realloc
*/

#include "my_malloc.h"

extern t_block *HEAP_START;

void *realloc(void *ptr, size_t size)
{
    t_block *this_block = ptr - sizeof(t_block);
    t_block *new_block;
    void *new;

    if (ptr == NULL)
        return malloc(size);
    if (this_block->size >= size) {
        return ptr;
    } else {
        new = malloc(size);
        new_block = new - sizeof(t_block);
        new_block->ptr = memcpy(new_block->ptr, this_block->ptr,
        this_block->size);
        free(ptr);
        return new_block->ptr;
    }
    return malloc(size);
}