#ifndef _MAIN_H
#define _MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>


char **adder(char *line, char *delim);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
#endif
