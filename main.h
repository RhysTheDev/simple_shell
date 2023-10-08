#ifndef HEADER_H
#define HEADER_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

int main(int argc, char *argv[]);
void display_prompt(void);
int _strlen(char *s);
char *get_input(int argc, char *argv[]);
void exec_command(char *input);
void wait_for_child(pid_t pid);

#define MAX_INPUT_SIZE 1024

#endif
