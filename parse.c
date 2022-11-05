#include "main.h"

/**
 * parse - parse input by breaking it up using spaces as delimiter
 * @input: input to be parsed
 *
 * Return: parsed input on success, otherwise -1
 */

char **parse(char *input)
{
	/* Parsing the input by breaking it up by spaces (default) */
	/* works as strtok function */

	int all_tokens_buffer = 100;
	char **all_tokens = malloc(all_tokens_buffer * sizeof(char*));
	int all_tokens_counter = 0;

	int current_token_buffer = 1024;
	char *current_token = malloc(current_token_buffer * sizeof(char));
	int current_token_counter = 0;

	for (int i = 0; i < strlen(input); i++)
	{
		char character = input[i];

		if (character == ' ')
		{
			if (all_tokens_counter + 1 > all_tokens_buffer)
			{
				all_tokens_counter += 100;
				all_tokens = realloc(all_tokens, all_tokens_buffer * sizeof(char*));
			}

			if (current_token_counter + 1 > current_token_buffer)
			{
				current_token_buffer +=1024;
				current_token = realloc(current_token, current_token_buffer);
			}

			all_tokens[all_tokens_counter] = current_token;
			all_tokens_counter++;

			current_token = malloc(current_token_buffer * sizeof(char*));
			current_token_counter = 0;
		}
		else if (character == '\n')
		{
			if (all_tokens_counter + 2 > all_tokens_buffer)
			{
				all_tokens_counter += 100;
				all_tokens = realloc(all_tokens, all_tokens_buffer * sizeof(char*));
			}

			if (current_token_counter + 1 > current_token_buffer)
			{
				current_token_buffer += 1024;
				current_token = realloc(current_token, current_token_buffer);
			}

			all_tokens[all_tokens_counter] = current_token;
			all_tokens_counter++;

			all_tokens[all_tokens_counter] = NULL;
			break;
		}
		else
		{
			if (current_token_counter + 1 > current_token_buffer)
			{
				current_token_buffer += 1024;
				current_token = realloc(current_token, current_token_buffer);
			}

			current_token[current_token_counter] = character;
			current_token_counter++;
		}
	}

	return (all_tokens);
}
