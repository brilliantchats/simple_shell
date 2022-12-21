#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success.
 */

int main(void)
{
	pid_t child;
	char **argv;
	size_t n, i;
	char *line;
	int status;
	ssize_t r;

	line = NULL;
	while (1)
	{
		write(1, "<3 ", 3);
		n = 0;
		r = getline(&line, &n, stdin);
		if (r == -1)
		{
			perror("read not successfull");
			return (1);
		}
		argv = adder(line, " ");
		child = fork();
		if (child == -1)
		{
			perror("problem while forking");
			return (1);
		}
		if (child == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error exec gone wrong:");
		}
		else
		{
			wait(&status);
		}
		for (i = 0; argv[i]; i++)
			free(argv[i]);
		free(argv);
		free(line);
	}
	return (0);
}
