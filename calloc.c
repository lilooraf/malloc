/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** calloc
*/

#include "my_malloc.h"

extern t_block *HEAP_START;

void *calloc(size_t elem_size, size_t elems)
{
    size_t alloc_size = elem_size * elems;
    void *block = malloc(alloc_size);
    unsigned char *ptr = block;

    for (; alloc_size; alloc_size--)
        *ptr++ = (unsigned char)(0);
    return (block);
}