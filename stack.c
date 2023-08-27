/**
 * init_stack - Initialize a struct stack type
 * @top: A pointer to the top node of the stack
 *
 * np - Pointer to node
 *
 * Return: 1 if no errors otherwise 0.
 */
#include "monty.h"

int init_stack(stack_t **top)
{
	stack_t *np = (stack_t *)malloc(sizeof(stack_t));

	if (np == NULL)
		return (error_malloc());

	*top = NULL;
	return (EXIT_SUCCESS);
}

/**
 * free_stack - free a struct stack type
 * @top: A pointer to the top node of the stack
 *
 * np - Pointer to node
 *
 * Return: 1 if no errors otherwise 0
 */
void free_stack(stack_t **top)
{
	stack_t *tmp;

	while (*top)
	{
		tmp = (*top)->next;
		free(*top);
		*top = tmp;
	}
}
