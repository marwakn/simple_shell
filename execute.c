#include "shell.h"
/**
 * _fork - function
 * @av: av
 * @argv: argv
 * @envp: envp
 * @full_path: ful path
 * Return: Integer
*/

int _fork(char **av, char **argv, char **envp, char *full_path)
{
	pid_t pid;
	int status;

		pid = fork();
	if (pid == -1)
	{
		perror(av[0]);
		free(full_path);
		return (-1);
	}
	else if (pid == 0)
	{

		if (execve(full_path, argv, envp) == -1)
		{
			perror(av[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror(av[0]);
			free(full_path);
			return (-1);
		}
	}
	if (full_path != NULL)
		free(full_path);
	return (0);
}
/**
 * execute - Function that executes the command
 * @cmd: Pointer to the command
 * @argv: Pointer to command's arguments
 * @av: Pointer to arguments
 * @envp: Pointer to environment variables
 * Return: Integer
 */
int execute(char *cmd, char **argv, char **av, char **envp)
{
	char *full_path = NULL;

	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) == 0)
		{
			full_path = malloc((strlen(cmd) + 1) * sizeof(char));
			if (full_path == NULL)
			{
				perror("Failed to allocate memory");
				return (-1);
			}
			_strcpy(full_path, cmd);
		}
		else
		{
			char error_message[100];

			_snprintf(error_message, sizeof(error_message),
			"%s: command not found\n", cmd);
			write(STDERR_FILENO, error_message, strlen(error_message));
			return (COMMAND_NOT_FOUND);
		}
	}
	else
	{
		if (!path(cmd, &full_path))
		{
			char error_message[100];

			_snprintf(error_message, sizeof(error_message),
			 "%s: command not found\n", cmd);
			write(STDERR_FILENO, error_message, strlen(error_message));
			return (COMMAND_NOT_FOUND);
		}
	}
	_fork(av, argv, envp, full_path);


	return (0);
}


