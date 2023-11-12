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

extern char** environ;
int main(int argc, char *argv[]);
void display_prompt(void);
int _strlen(char *s);
char *get_input(int argc, char *argv[]);
void wait_for_child(pid_t pid);
char *_get_path_of_exe(char *command);
void exec_command(char *input, char **command_args);
char *_getenv(char *name);
int _strncmp(char *str1, char *str2, int n);



#define MAX_INPUT_SIZE 1024

#endif
