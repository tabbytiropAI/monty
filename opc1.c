#include "monty.h"

/**
 * _pall - function print stack
 * @stack: the opcode
 * @line_number: function to handle the opcode
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
