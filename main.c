#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "monty.h"

#define BUFFER_SIZE 1024

/**
* main - entry point.
* @argc: argument count
* @argv: argument vector
*
* Return: 0 on success, non-zero on failure.
*/
int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}

FILE *file = fopen(argv[1], "r");
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
return (EXIT_FAILURE);
}

stack_t *stack = NULL;
char line[BUFFER_SIZE];

while (fgets(line, sizeof(line), file) != NULL)
{
int read = strlen(line);
{
char *opcode = strtok(line, " \t\n");
if (opcode)
{
if (strcmp(opcode, "push") == 0)
{
char *arg = strtok(NULL, " \t\n");
if (arg && is_number(arg))
{
push(&stack, atoi(arg));
}
else
{
fprintf(stderr, "L%d: usage: push integer\n");
free(line);
fclose(file);
free_stack(&stack);
return (EXIT_FAILURE);
}
}
else
{
instruction_t *instruction = get_instruction(opcode);
if (instruction)
{
instruction->f(&stack, line_number);
}
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
free(line);
fclose(file);
free_stack(&stack);
return (EXIT_FAILURE);
}
}
}
line_number++;
}
free(line);
fclose(file);
free_stack(&stack);
return (EXIT_SUCCESS);
}
