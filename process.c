#include <sys/stat.h>
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
 * execute - Executes the commands passed by the user
 * @args: command line args
 *
 * Return: void
  */

int execute(char **args)
{
	pid_t my_pid;
	char *command = args[0];
	int status;

	my_pid = fork();
	if (my_pid == -1)
	{
		perror("hsh");
	}

	if (my_pid == 0)
	{
		/*mainExecCommand*/
		if (command[0] == '/' || command[0] == '.')
			command = args[0];
		else
			command = _get_path_of_exe(command);
		if (!command)
		{
			perror("hsh");
			return (0);
		}
		executeCommand(command, args);
	}
	else
		wait(&status);
	return (1);
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
	ssize_t token_len;
	ssize_t command_len;
	size_t full_path_len;
	char *full_path;
	struct stat st;

	if (path_copy == NULL)
		perror("Can't find path");

	command = _get_path_of_exe(command);
	while (token != NULL)
	{
		token_len = _strlen(token);
		command_len = _strlen(command);
		full_path_len = token_len + command_len + 2;
		full_path = malloc(full_path_len);

		_strcnpy(full_path, token, token_len);
		_strcnpy(full_path + token_len + 1, command, command_len + 1);
		printf("full_path: %s\n", full_path);

		if (access(full_path, X_OK) == 0 && stat(full_path, &st) == 0)
		{
			args[0] = _strdup(full_path);
			executeCommand(full_path, args);
			free(args[0]);
			free(full_path);
			return;
		}
		token = _strtok(NULL, ":");
	}

	perror("hsh");
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
	char **arguments;

	arguments = _splitline(input);
	if (arguments == NULL)
	{
		free(input);
		free(arguments);
	}
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
		if (access(arguments[0], X_OK) == 0)
			executeCommand(arguments[0], arguments);
		else
			execute(arguments);

	}
}



