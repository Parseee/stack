#pragma once

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <memory.h>

typedef struct Stack {
    void** data;
    size_t element_size;
    size_t size;
    size_t capacity;
} Stack;

void Stack_create(Stack* stack, int element_size, int capacity);
void Stack_push(Stack* stack, const void* const data);
void Stack_pop(Stack* stack);
void* Stack_top(Stack* stack);
void Stack_clear(Stack* stack, const int capacity);