#include "monty.h"

/**
*_push - pushes an element to the stack_s
*@head: stack head
*@line_number: line number which opcode occurs on
*Return: void
*/
void _push(stack_t **stack, unsigned int line_number)
{
	int n, j = o, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integr\n", counter);
			fclose(bus.file);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg)	;
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}

/**
*_pall - prints all the values on the stack, starting from the top of the stack
*@head: head of stack
*@line_number: line number opcode occurs on
*Return: void
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *head;
	if (h == NULL)
		return;

	while (h)
	{
		printf("%d\n", temp->n);
		h = h->next;
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
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		error_exit(stack);
	}
	delete_dnodeint_at_index(stack, 0);
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
