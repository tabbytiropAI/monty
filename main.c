/**
 * main - the entry point for Monty Interpreter
 *
 * @argc: the count of arguments passed to the program
 * @argv: pointer to an array of char pointers to arguments
 *
 * Return: (EXIT_SUCCESS) or (EXIT_FAILURE).
 */
#include "monty.h"

int main(int argc, char **argv)
{
	/**
	 * Declaration main local variables
	 *
	 * return_code - exit code
	 * fileptr     - Pointer to input monty file
	 */

	int return_code;
	FILE *fileptr = NULL;

	if (argc < 2 || argc > 2)
		return (error_usage_file());

	fileptr = fopen(argv[1], "r");

	if (fileptr == NULL)
		return (error_open_file(argv[1]));

	(return_code) = exec_monty(fileptr);

	fclose(fileptr);
	return (return_code);
}
