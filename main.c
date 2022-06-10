/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_malloc.h"

extern t_block *HEAP_START;

int main(void)
{
    int ret;
    void *ptr = NULL;
    t_block *i;
    t_block *end;
    unsigned int nb = 0;
    unsigned int nbf = 0;

    for (size_t j = 0; j < 121123; j++)
        malloc(j);
    /* for (size_t j = 0; j < 121123; j++)
        malloc(j); */

    i = HEAP_START;
    end = sbrk(0);

    for (; (size_t)i < (size_t)end; i = i->ptr + i->size, nb++)
        if (i->free)
            nbf++;
    printf("free blocks :%d\n", nbf);
    printf("nb block :%d\n", nb);
}