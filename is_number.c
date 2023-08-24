#include "monty.h"

/**
* is_number - Checks if a string represents a valid integer.
* @str: The input string.
* Return: 1 if the string is a number, 0 otherwise.
*/
int is_number(char *str)
{
int i;

if (!str)
return (0);

for (i = 0; str[i] != '\0'; i++)
{
if (str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9'))
return (0);
}
return (1);
}
