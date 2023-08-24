#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
* push - Pushes an element onto the stack.
* @stack: Pointer to a pointer to the top of the stack.
* @line_number: The current line number in the Monty bytecode file.
*/
void push(stack_t **stack, int value)
{
stack_t *new_node = malloc(sizeof(stack_t));
if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = value;
new_node->prev = NULL;

if (*stack)
{
new_node->next = *stack;
(*stack)->prev = new_node;
}
else
{
new_node->next = NULL;
}

*stack = new_node;
}

/**
* pall - Prints all elements in the stack.
* @stack: Pointer to the top of the stack.
* @line_number: The current line number in the Monty bytecode file.
*/
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;

while (current)
{
printf("%d\n", current->n);
current = current->next;
}
(void)line_number;
}
