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
int _atoi(char *str);

char *_getline(size_t *input_size);

int _strcmp(char *s1, char *s2);

int _strcspn_(const char *str, const char *reject);

char *_strdup(char *str);

void _strcnpy(char *dest, const char *src, size_t n);

char *_strtok(char *str, const char *delim);

char *display_prompt(void);

void exitShell(char *buffer);

char *_getenv(char *name);

char *get_input(size_t *input_size);

char *_get_path_of_exe(char *command);

void printEnvironment(void);

int tokenize(char *input, char *tokens[]);

void executeCommand(char *command, char *args[]);

void searchAndExecute(char *command, char *args[]);

void mainExecCommand(char *input);

void checkChildProcess(pid_t pid);

int main(void);

int _strlen(char *s);

int _strncmp(char *str1, char *str2, int n);

char **tokenize_env(char *path);

char *_strcat(char *dest, char *src);

void readInput(char *buffer, size_t *buffer_index, size_t *bs, char *line);

int execute(char *command, char *args[]);

#define MAX_INPUT_SIZE 1024

#endif
