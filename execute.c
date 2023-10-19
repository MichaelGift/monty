#include "monty.h"
/**
 * execute_opcode - Execute the given opcode
 * @content: Line content
 * @stack: Pointer to the stack
 * @counter: Line Counter
 * @file: Pointer to the Monty file
 * Return: 0 if successful else 1
 */
int execute_opcode(char *content,
		stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opcodes[] = {
		{"push", f_push}, {"pall", print_stack}, {"pint", f_pint},
		{"pop", f_pop}, {"swap", f_swap}, {"add", add_top_two_elements},
		{"nop", do_nothing}, {"sub", f_sub}, {"div", divide_top_two_elements},
		{"mul", multiply_top_two_elements},
		{"mod", compute_modulus}, {"pchar", f_pchar},
		{"pstr", f_pstr}, {"rotl", f_rotl}, {"rotr", f_rotr},
		{"queue", f_queue}, {"stack", f_stack}, {NULL, NULL}};

	unsigned int i = 0;
	char *opcode;

	opcode = strtok(content, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);

	bus.arg = strtok(NULL, " \n\t");

	while (opcodes[i].opcode && opcode)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (opcode && opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}

