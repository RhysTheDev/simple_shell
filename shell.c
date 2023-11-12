#include "main.h"
#define MAX_INPUT_SIZE 1024

/**
 * main - function to initialize shell
 * @argc: number of command line args
 * @argv: array of ptrs to command line args
 *
 * Return: 1 if success; 0 if failure
 */
int main(int argc, char *argv[])
{
    int status = 1;
	while (status)
	{
        display_prompt();

        status = isatty(STDIN_FILENO);
        if (status == 1)
            write(STDOUT_FILENO, "$ ", 2);

		char *input, *executable, *command_args[MAX_INPUT_SIZE];
		int i = 1;
		pid_t pid;

		input = get_input(argc, argv);

		executable = _get_path_of_exe(input);
		if (executable == NULL)
		{
			printf("No such file or directory");
			exit(EXIT_FAILURE);
		}
		command_args[0] = executable;
		while (i < argc)
		{
			command_args[i] = argv[i];
			i++;
		}
		command_args[argc] = NULL;

		pid = fork();
		if (input == NULL)
		{
			printf("\n");
			break;
		}

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		} else if (pid == 0)
			exec_command(executable, command_args);
		else
			wait_for_child(pid);

		free(input);
	}
	return (EXIT_SUCCESS);
}

