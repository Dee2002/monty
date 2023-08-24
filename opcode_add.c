#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
* add - Adds the top two elements of the stack.
* @stack: Pointer to the top of the stack.
* @line_number: Line number in the Monty bytecode file.
*/
void add(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (!stack || !(*stack) || !(*stack)->next)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

(*stack)->next->n += (*stack)->n;
temp = *stack;
*stack = (*stack)->next;
(*stack)->prev = NULL;
free(temp);
}
