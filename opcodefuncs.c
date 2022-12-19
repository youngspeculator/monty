#include "monty.h"

/**
*_push - pushes an element to the stack_s
*@stack: points to linked list stack_t
*@line_number: line number which opcode occurs on
*Return: void
*/
void _push(stack_t **stack, unsigned int line_number)
{
	int deflt = 0;
	stack_t *new;
	char *arg;
	int push_arg;

	push_arg = 0;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		error_exit(stack);
	}

	arg = strtok(NULL, "\n ");
	if (isnumber(arg) == 1 && arg != NULL)
	{
		push_arg = atoi(arg);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		error_exit(stack);
	}

	if (deflt == 1)
	{
	add_dnodeint_end(stack, push_arg);
	}

	if (deflt == 0)
	{
		add_dnodeint(stack, push_arg);
	}
	free(new);
}

/**
*_pall - prints all the values on the stack, starting from the top of the stack
*@stack: points to linked list stack_t
*@line_number: line number opcode occurs on
*Return: void
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
*_pint - prints the value at the top of the stack, fbanl
*@stack: points to linked list stack_t
*@line_number: line number which opcode occurs on
*Return: void
*/
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n",  line_number);
		error_exit(stack);
	}
	printf("%d\n", temp->n);
}

/**
*_pop - removes the top element of the stack
*@stack: points to the linked list stack_t
*@line_number: line number which opcode is found on
*Return: void
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_numver);
		error_exit(stack);
	}
	delete_dnodeint_at(stack, 0);
}

/**
 *_swap - swaps the top two elements of the stack
 *@stack: points to the linked list stack_t
 *@line_number: line number which the opcode occurs
 *Return: void
*/
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int tmp;

	if (!temp || !temp->next)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		error_exit(stack);
	}
	tmp = temp->n;
	temp->n = temp->next->n;
	temp->next->n = tmp;
}
