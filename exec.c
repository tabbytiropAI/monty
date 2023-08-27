#include "monty.h"
#include <stdio.h>

/**
 * exec_monty - Execute interpreter monty code
 * @fileptr: Pointer to input monty file
 *
 * fileptr     - Pointer to input monty file
 * lineptr     - Pointer to buffer line read
 * len_buff    - The buffer size of lineptr
 * Stack       - Pointer to struct stack_t
 * func_ptr    - Pointer to the corresponding function
 * line_number - Working Line number from monty file
 * getline     - getline
 * Return: (EXIT_SUCCESS) or (EXIT_FAILURE).
 */

int exec_monty(FILE *fileptr)
{
	char *lineptr = NULL;
	size_t len_buff = 0;
	stack_t *Stack = NULL;
	void (*func_ptr)(stack_t **, unsigned int);
	int line_number = 1;

	if (init_stack(&Stack) == EXIT_FAILURE)
	{
		free_all(lineptr);
		return (EXIT_FAILURE);
	}

	while ((getline(&lineptr, &len_buff, fileptr)) != -1)
	{
		line_number++;
		info.opc_code = strtok(lineptr, DELIMITERS);

		if (info.opc_code == NULL || strncmp(info.opc_code, "#", 1) == 0)
			continue;

		info.val_arg = strtok(NULL, DELIMITERS);

		func_ptr = get_address_func();
		if (func_ptr == NULL)
		{
			free_all(lineptr);
			free_stack(&Stack);
			return (error_unknown_instruction(line_number));
		}

		func_ptr(&Stack, line_number);
		if (info.error_in_func)
		{
			free_all(lineptr);
			free_stack(&Stack);
			return (EXIT_FAILURE);
		}
	}

	return (EXIT_SUCCESS);
}

/**
 * get_address_func - Get address from a function monty interpreter
 *
 * Return: A pointer to function to execute
 */

void (*get_address_func())(stack_t **top, unsigned int)
{
	instruction_t *ins_ptr;
	instruction_t func[] = {{"push", _push},
							{"pall", _pall},
							{NULL, NULL}};

	ins_ptr = func;

	while (ins_ptr->opcode && strcmp(info.opc_code, ins_ptr->opcode))
		ins_ptr++;

	return (ins_ptr->f);
}

/**
 * isnumber - Function for determinate if argument is a valid number
 *
 * Return: true if argument is a number otherwise false
 */
bool isnumber(void)
{
	char *val_arg = info.val_arg;

	if (info.val_arg == NULL)
		return (false);

	while (val_arg != NULL)
	{
		if ((val_arg == info.val_arg) && *val_arg == '-')
		{
			val_arg++;
			continue;
		}

		if (*val_arg == '\0')
			break;

		if (*val_arg < '0' || *val_arg > '9')
			return (false);

		val_arg++;
	}
	return (true);
}

/**
 * free_all - Free all variables and pointers
 * @lineptr: Pointer to buffer read by getline() function
 */
void free_all(char *lineptr)
{
	free(lineptr);
	free(info.opc_code);
}
