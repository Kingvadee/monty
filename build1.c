#include "monty.h"

/**
 * push - Add node to the stack
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void push(stack_t **stack, unsigned int line_number)
{

	int x = 0;

	if (globalvar.token2 == NULL)
	{
		free_dlistint(*stack);
		stderr_int(line_number);
	}
	if (!_isdigit() || stack == NULL)
	{
		free_dlistint(*stack);
		stderr_int(line_number);
	}
	x = atoi(globalvar.token2);
	if (*stack  == NULL)
	{
		create_node_stackfirst(stack, x);
	}
	else
	{
		create_node_stackend(stack, x);
	}
}

/**
 * pall - Print the stack
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void pall(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;


	if (*stack == NULL)
	{
		return;
	}
	if (*stack == NULL && line_number != 1)
	{
		free_dlistint(*stack);
		free_globalvars();
		exit(EXIT_SUCCESS);
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		printf("%d", temp->n);
		temp = temp->prev;
		printf("\n");
	}
	printf("%d\n", temp->n);
}


/**
 * pint - Print the stack
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void pint(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;

	if (stack == NULL || *stack == NULL)
	{
		pint_e(line_number);
		return;
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	printf("%d", temp->n);
	printf("\n");
}

/**
 * swap - Print the stack
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int s, d;

	if (*stack == NULL || stack == NULL)
		op_e(line_number, "swap");

	temp = (*stack)->next;
	if ((*stack)->next == NULL)
		op_e(line_number, "swap");
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	s = temp->n;
	d = temp->prev->n;
	temp->n = d;
	temp->prev->n = s;
}
/**
 * nop - does not do anything
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
