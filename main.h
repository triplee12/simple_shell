#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

typedef struct aliases {
    char *alias_name;
    char *real_name;
} alias;

typedef struct my_builtins{
    char *name;
    int (*func)(void);
} my_builtins;

void execute(char **args);
char **parse(char *input);
char *read_line();
int _strcmp(char *str1, char *str2);
int _strcpy(char *str1, char *str2, int s);

#endif
