#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>


/*#### Data Stractures ####*/

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

/*
 * ### Monty Prototypes 
 * ###*/
int main(int argc, char **argv);

void monty_free_stack(stack_t **stack);

/*
 * ### Monty Run File 
 * ###*/
int monty_run(FILE *file);
char **tokenize_line(char *line, char *delimiters);
int monty_empty_line(char *line, char *delimiters);


/* 
 * ### Monty Pool 3 
 * ###*/
void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);

/*
 * ### Monty Errors Checkers 
 * ###*/
int monty_usage_error(int error_flag);
int monty_open_error(char *filename);
int monty_f_errors(int error_flag, unsigned int line_number);

#endif /* __MONTY_H__ */
