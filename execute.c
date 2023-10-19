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
		{"push", push_node}, {"pall", print_stack}, {"pint", print_int},
		{"pop", print_top}, {"swap", swap_top_two}, {"add", add_top_two},
		{"nop", do_nothing}, {"sub", substract}, {"div", divide_top_two},
		{"mul", multiply_top_two},
		{"mod", modulo}, {"pchar", print_char},
		{"pstr", print_str}, {"rotl", rotate_stack_top}, {"rotr", rotate_stack_bottom},
		{"queue", print_q_top}, {"stack", print_s_top}, {NULL, NULL}};

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

