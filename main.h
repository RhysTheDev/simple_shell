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

int _strncmp(char *str1, char *str2, int n);

int _strlen(char *s);

int _strcmp(char *s1, char *s2);

int main(void);

void mainExecCommand(char *input);

int tokenize(char *input, char *tokens[]);

void executeCommand(char *command, char *args[]);

void searchAndExecute(char *command, char *args[]);

void checkChildProcess(pid_t pid);

char *_get_path_of_exe(char *command);

char *_getenv(char *name);

char *display_prompt(void);

void _strcnpy(char *dest, const char *src, size_t n);

char *_strdup(char *str);

int _strcspn_(const char *str, const char *reject);

char *get_input(size_t *input_size);

void sigintHandler(int signal);

void printEnvironment(void);

char *_getline(size_t *input_size);

char *_strtok(char *str, const char *delim);

void exitShell(char *buffer);

int _atoi(char *str);


#define MAX_INPUT_SIZE 1024

static char buffer[MAX_INPUT_SIZE];
static size_t buffer_index;
static size_t buffer_size;

#endif
