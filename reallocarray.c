/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** reallocarray
*/

#include "my_malloc.h"

void *reallocarray(void *ptr, size_t nb, size_t size)
{
    return realloc(ptr, size * nb);
}