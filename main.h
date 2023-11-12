#ifndef HEADER_H
#define HEADER_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <limits.h>
#include <errno.h>

extern char **environ;

int main(void);

char *_strdup(char *str);

void _strcnpy(char *dest, const char *src, size_t n);

char *display_prompt(void);

int _strlen(char *s);

char *get_input(size_t *input_size);

void checkChildProcess(pid_t pid);

char *_get_path_of_exe(char *command);

void mainExecCommand(char *input);

char *_getenv(char *name);

int _strncmp(char *str1, char *str2, int n);

int _strcspn_(const char *str, const char *reject);


#define MAX_INPUT_SIZE 1024

#endif
