#include "main.h"
/**
 * tokenize - split string into an array of tokens
 * @input: string to tokenize
 * @tokens: array of tokens
 *
 * Return: number of tokens
 */
int tokenize(char *input, char *tokens[])
{
	int i = 0;
	char *token = _strtok(input, " ");

	while (token != NULL)
	{
		tokens[i++] = token;
		token = _strtok(NULL, " ");
	}
	tokens[i] = NULL;
	return (i);
}

/**
 * executeCommand - execute command with execve
 * @command: command to execute
 * @args: command line args
 *
 * Return: void
 */
void executeCommand(char *command, char *args[])
{
	if (execve(command, args, NULL) == -1)
		perror("hsh");
}

/**
 * searchAndExecute - search for command in PATH
 * @command: command to execute
 * @args: arguments
 *
 * Return: void
 */
void searchAndExecute(char *command, char *args[])
{
	char *path = _getenv("PATH");
	char *path_copy = _strdup(path);
	char *token = strtok(path_copy, ":");

	while (token != NULL)
	{
		size_t token_len = _strlen(token);
		size_t command_len = _strlen(command);
		size_t full_path_len = token_len + command_len + 2;

		char *full_path = malloc(full_path_len);

		_strcnpy(full_path, token, token_len);
		full_path[token_len] = '/';
		_strcnpy(full_path + token_len + 1, command, command_len + 1);

		if (access(full_path, X_OK) == 0)
		{
            printf("Executing: %s\n", full_path);
			args[0] = _strdup(full_path);
			executeCommand(full_path, args);
			free(args[0]);
            free(full_path);
			return;
		}
		token = _strtok(NULL, ":");
	}

	perror("hsh: problem here");
}

/**
 * mainExecCommand -  execute command passed
 * @input: string command input by user
 *
 * Return: None
 */
void mainExecCommand(char *input)
{
	char *args[MAX_INPUT_SIZE / 2 + 1];
	char *home_dir;
	char *old_pwd;
	int arg_count = tokenize(input, args);


	if (arg_count > 0 && _strcmp(args[0], "cd") == 0)
	{
		home_dir = _getenv("HOME");
		old_pwd = _getenv("OLDPWD");

		if (arg_count == 1 || _strcmp(args[1], "~") == 0)
			chdir(home_dir);
		else if (_strcmp(args[1], "-") == 0)
			chdir(old_pwd ? old_pwd : ".");
		else
		{
			if (chdir(args[1]) == -1)
				perror("cd");
		}

		setenv("OLDPWD", _getenv("PWD"), 1);
		setenv("PWD", getcwd(NULL, 0), 1);
	}
	else
	{
		free(input);
		if (access(args[0], X_OK) == 0)
			executeCommand(args[0], args);
		else
			searchAndExecute(args[0], args);
	}
}

/**
 * checkChildProcess -  takes PID of child process and waits for it to end
 * @pid: PID of the child process to wait for
 *
 * Return: None
 */
void checkChildProcess(pid_t pid)
{
	int status = 0;

	if (waitpid(pid, &status, 0) == -1)
	{
		perror("Error waiting for child process");
		exit(EXIT_FAILURE);
	}

	/* Check if the child process exited successfully */
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		write(STDERR_FILENO, "Error: Command not found\n", 25);
}

