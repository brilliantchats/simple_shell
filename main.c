#include "main.h"

/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */

int main(int argc, char ** argv)
{
	pid_t child;
	char **argv1;
	size_t n, i;
	char *line;
	int status;
	ssize_t r;

	line = NULL;
	while (1)
	{
		write(1, "<3 ", 3);
		n = argc - 1;
		r = getline(&line, &n, stdin);
		if (r == -1)
		{
			perror("read not successfull");
			return (1);
		}
		argv1 = adder(line, " ");
		child = fork();
		if (child == -1)
		{
			perror("problem while forking");
			return (1);
		}
		if (child == 0)
		{
			if (execve(argv1[0], argv1, NULL) == -1)
				perror(argv[0]);
		}
		else
		{
			wait(&status);
		}
		for (i = 0; argv1[i]; i++)
			free(argv1[i]);
		free(argv1);
		free(line);
	}
	return (0);
}
