# 0x19. C - Stacks, Queues - LIFO, FIFO

## Learning Objectives

At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

### General
- What LIFO and FIFO mean
- What a stack is, and when to use it
- What a queue is, and when to use it
- Common implementations of stacks and queues
- Most common use cases of stacks and queues
- Proper usage of global variables

## Requirements

### General
- Allowed editors: vi, vim, emacs
- Compilation options: `-Wall -Werror -Wextra -pedantic -std=c89`
- Files should end with a new line
- A `README.md` file at the root of the project folder is mandatory
- Code should follow the Betty style (checked using `betty-style.pl` and `betty-doc.pl`)
- You are allowed to use a maximum of one global variable
- Each file should have no more than 5 functions
- C standard library functions are allowed
- Prototypes of all functions should be included in a header file named `monty.h`
- Don’t forget to push your header file
- All header files should be include guarded
- Tasks are expected to be completed in the order shown in the project

## Data Structures

Please use the following data structures for this project:

```c
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

## Compilation & Output

Your code will be compiled using the following command:

```sh
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

## Monty Language & Byte Code Files

Monty 0.98 is a scripting language that is first compiled into Monty byte codes. It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Monty byte code files usually have the `.m` extension. There is not more than one instruction per line. Blank lines or extra text after the opcode and its required argument are not taken into account.

## The Monty Program

Usage: `monty file`

- Replace `file` with the path to the Monty byte code file.
- If no file is given or more than one argument is provided, print the error message `USAGE: monty file`, followed by a new line, and exit with status `EXIT_FAILURE`.
- If the file cannot be opened, print the error message `Error: Can't open file <file>`, followed by a new line, and exit with status `EXIT_FAILURE`.
- If the file contains an invalid instruction, print the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with status `EXIT_FAILURE`.
- The program stops if it successfully executes every line of the file, finds an error in the file, or encounters a runtime error.
- If memory allocation fails, print the error message `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE`. You must use `malloc` and `free` and are not allowed to use other memory allocation functions like `realloc` or `calloc`.

---
### General
