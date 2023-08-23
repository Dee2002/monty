#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
* push - Pushes an element onto the stack.
* @stack: Pointer to the top of the stack.
* @line_number: Line number in the Monty bytecode file.
*/
void push(stack_t **stack, unsigned int line_number)
{
char *arg = strtok(NULL, " \t\n");

if (!arg || !is_number(arg))
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

stack_t *new_node = malloc(sizeof(stack_t));
if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = atoi(arg);
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
* pall - Prints all values on the stack.
* @stack: Pointer to the top of the stack.
* @line_number: Line number in the Monty bytecode file.
*/
void pall(stack_t **stack, unsigned int line_number)
{
(void)line_number;

stack_t *current = *stack;

while (current)
{
printf("%d\n", current->n);
current = current->next;
}
}

/**
* is_number - Checks if a string is a number.
* @str: The string to check.
* Return: 1 if the string is a number, 0 otherwise.
*/
int is_number(char *str)
{
if (!str)
return (0);

for (int i = 0; str[i]; i++)
{
if (i == 0 && (str[i] == '-' || str[i] == '+'))
continue;

if (str[i] < '0' || str[i] > '9')
return (0);
}

return (1);
}
