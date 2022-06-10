/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** malloc
*/

#ifndef MY_MALLOC_H_
#define MY_MALLOC_H_

#include <unistd.h>
#include <string.h>
#include <pthread.h>

typedef struct s_block
{
    char free;
    size_t size;
    void *ptr;
    void *first_free;
    long free_nb;
    void *prev;
} t_block;

void free(void *);
void *malloc(size_t);
void *realloc(void *, size_t);
void *reallocarray(void *, size_t, size_t);
void *calloc(size_t, size_t);

#endif /* !MALLOC_H_ */
