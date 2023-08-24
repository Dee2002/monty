#include "monty.h"

/**
* free_stack - Frees the memory occupied by the stack.
* @stack: Pointer to a pointer to the top of the stack.
*/
void free_stack(stack_t **stack)
{
while (*stack)
{
stack_t *temp = *stack;
*stack = (*stack)->next;
free(temp);
}
}
