#include "monty.h"

/**
 *pint - prints the element at the top of the stack
 *@stack: stack to print the element from
 *@line_number: the line number of the opcode currently being executed
*/
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		fprint(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}
