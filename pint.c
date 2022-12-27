#include "monty.h"

/**
* f_pint - prints the value at the top of the stack, fbanl
* @head: head of stack
* @number: line number which opcode occurs on
* Return: void
*/
void f_pint(stack_t **head, unsigned int number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n",  line_number);
		fclose(bus.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", *head->n);
}

