#include "stack.h"

#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

void Stack_create(Stack* stack, int element_size, int capacity)
{
    assert(stack && "stack is NULL");

    stack->data = (void*)malloc(capacity * sizeof(void*));
    stack->element_size = element_size;
    stack->capacity = capacity;
    stack->size = 0;
}

void Stack_push(Stack* stack, const void* const data)
{
    assert(stack && "stack is NULL");

    if (stack->data == NULL) {
        stack->data = malloc(stack->capacity * sizeof(void*));
    }
    if (stack->size + 1 >= stack->capacity) {
        void* old_data = *stack->data;
        stack->capacity = MAX(stack->capacity * 1.5f, stack->size + 1);
        stack->data = realloc(stack->data, stack->capacity * sizeof(void*));
    }

    ++stack->size;
    stack->data[stack->size - 1] = malloc(stack->element_size);
    memcpy(stack->data[stack->size - 1], data, stack->element_size);
}

void Stack_pop(Stack* stack)
{
    assert(stack && "stack is NULL");
    assert(stack->size && "stack is empty");

    free(stack->data[stack->size - 1]);
    --stack->size;
}

void* Stack_top(Stack* stack)
{
    return stack->data[stack->size - 1];
}

void Stack_clear(Stack* stack, const int capacity)
{
    assert(stack && "stack is null");

    for (int i = 0; i < stack->size; ++i) {
        assert(stack->data[i] && "some element of stack is NULL");
        free(stack->data[i]);
    }
    free(stack->data);
    stack->size = 0;
    stack->capacity = 50; // or add some value?
    stack->data = (void*)malloc(stack->capacity * sizeof(void*));
}