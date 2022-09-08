#include "main.h"

/**
 * error_exit_shell - generic error message for exit in get_exit
 * @args: type array of args that is passed to the command.
 * Return: Error
 */
char *error_exit_shell(char **args)
{
	int count = 0;
	int lenght;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(count);
	if (ver_str == 0)
		return (NULL);
	lenght = _strlen(ver_str) + _strlen(args[0]) + 30;
	error = malloc(sizeof(char) * (lenght + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": command failed to execute");
	_strcat(error, args[0]);
	_strcat(error, "\n");
	free(ver_str);
	return (error);
}
/**
 * error_syntax - generic error message for syntax error.
 * @args: type array of args that is passed to the command.
 * Return: error.
 */
char *error_syntax(char **args)
{
	int count = 0;
	int lenght;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(count);
	if (ver_str == 0)
		return (NULL);
	lenght = _strlen(ver_str) + _strlen(args[0]) + 32;
	error = malloc(sizeof(char) * (lenght + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": syntax error: ");
	_strcat(error, args[0]);
	_strcat(error, " unexpected\n");
	free(ver_str);
	return (error);
}
/**
 * error_env - error message for env in get_env.
 * @args: type aray of args that is passed to the command.
 * Return: error.
 */
char *error_env(char **args)
{
	int count = 0;
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(count);
	if (ver_str == 0)
		return (NULL);
	length = _strlen(ver_str) + _strlen(args[0]) + 32;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, args[0]);
	_strcat(error, ": unable to locate env file\n");
	free(ver_str);
	return (error);
}
/**
 * error_permission - generic error message for permission.
 * @args: type array of args that is passed to the command.
 * Return: error.
 */
char *error_permission(char **args)
{
	int count = 0;
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(count);
	if (ver_str == 0)
		return (NULL);
	length = _strlen(ver_str) + _strlen(args[0]) + 27;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, args[0]);
	_strcat(error, ": permission not found\n");
	free(ver_str);
	return (error);
}
