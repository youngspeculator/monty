#include "monty.h"

/**
 *pall - function that prints all the values of the stack
 *@stack: the address of the stack to printf
 *@line_number: the line number of the opcode being executed
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	int counter = 0;
	(void) line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		counter++;
		temp = temp->next;
	}
}
