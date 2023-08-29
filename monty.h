#ifndef MONTY_H
#define MONTY_H

/* Macros */
#define BUFFER_SIZE 1024

/* Global */
extern FILE *file;

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

/* from main.c */
int extractInstruction(char *line, unsigned int line_num, stack_t **ps);

/* from basic_stack.c */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **ps);


/* from more_stack.c */
void swap(stack_t **stack, unsigned int line_number);

/* from checks.c */
int is_number(char *arg);
void checkArguments(int num_args, char **list_args);
FILE  *checkFile(char *file);

#endif
