#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * fork_shell - Calls fork to run the shell
 * @str: array of strings with commands and arguments
 *
 * Return: nothing
 */
void fork_shell(char *str[])
{
	pid_t child;
	int x, wstatus;

	if (str[0])
	{
		child = fork();
		if (child == -1)
		{
			perror(str[0]);
			exit(-1);
		}
		if (child == 0)
		{
			x = execve(str[0], str, environ);
			if (x == -1)
			{
				perror(str[0]);
				exit(-1);
			}
		}
		else
			wait(&wstatus);
	}
}
/**
 * main - Entry Point for the shell program
 *
 * Return: 0 on Success, anything else is failure
 */
int main(void)
{
	char *string[128];
	char *token, *lineptr = NULL;
	int i = 1;
	ssize_t line;
	size_t n = 0;

	while (1)
	{
		write(1, "$$", 2);
		line = getline(&lineptr, &n, stdin);
		if (line == -1)
			exit(-1);
		token = strtok(lineptr, " \n");
		string[0] = token;
		while (token != NULL)
		{
			token = strtok(NULL, " \n");
			string[i] = token;
			i++;
		}
		fork_shell(string);
		i = 1;
	}
	free(lineptr);
	return (0);
}
