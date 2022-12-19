#include "monty.h"

/**
*_push - pushes an element to the stack_s
*@head: stack head
*@line_number: line number which opcode occurs on
*Return: void
*/
void _push(stack_t **head, unsigned int line_number)
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
	n = atoi(bus.arg);
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
void _pall(stack_t **head, unsigned int line_number)
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
*@head: head of stack
*@line_number: line number which opcode occurs on
*Return: void
*/
void _pint(stack_t **head, unsigned int line_number)
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

/**
*_pop - removes the top element of the stack
*@head: head of stack
*@line_number: line number which opcode is found on
*Return: void
*/
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

/**
 *_swap - swaps the top two elements of the stack
 *@head: head of stack
 *@line_number: line number which the opcode occurs
 *Return: void
*/
void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
