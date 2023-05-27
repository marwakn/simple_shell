#include "shell.h"

/**
 * split - Function that splits a string into tokens
 * @line: Pointer to the string
 * Return: Array of tokens
 */
char **split(char *line)
{
	char *token;
	char **tokens = malloc(100 * sizeof(char *));
	int i = 0;
	int is_token = 0;

	if (!tokens)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\n");
	if (token == NULL)
	{
		free(tokens);
		return (NULL);
	}

	while (token != NULL && i < 99)
	{
		if (is_token == 0 && token[0] == ' ')
		{
			token = strtok(NULL, " \t\n");
			continue;
		}
		tokens[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
		is_token = 1;
	}
	tokens[i] = NULL;

	if (i >= 99)
	{
		free(tokens);
		return (NULL);
	}

	return (tokens);
}
