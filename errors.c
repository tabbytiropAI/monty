/**
 * error_usage_file - Prints usage error messages.
 * Return: (EXIT_FAILURE) always.
 */
#include "monty.h"

int error_usage_file(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * error_open_file - Prints usage error messages.
 * @file_ptr: Input fil to open
 * Return: (EXIT_FAILURE) always.
 */
int error_open_file(char *file_ptr)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_ptr);
	return (EXIT_FAILURE);
}

/**
 * error_malloc - Prints malloc error message.
 *
 * Return: (EXIT_FAILURE) always.
 */
int error_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * error_no_integer - Prints error message argument no valid.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int error_no_integer(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * error_unknown_instruction - Print error message unknown instruction.
 * @line_number: Working line number from input monty file.
 * Return: (EXIT_FAILURE) always.
 */
int error_unknown_instruction(unsigned int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, info.opc_code);
	return (EXIT_FAILURE);
}
