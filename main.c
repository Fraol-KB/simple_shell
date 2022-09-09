#include "main.h"

/**
 * free_data - frees data structure
 *
 * @datash: data structure
 * Return: no return
 */
void free_data(data_shell *datash)
{
	unsigned int i;

	for (i = 0; datash->_environ[i]; i++)
	{
		free(datash->_environ[i]);
	}

	free(datash->_environ);
	free(datash->pid);
}

/**
 * set_data - Initialize data structure
 *
 * @datash: data structure
 * @av: argument vector
 * Return: no return
 */
void set_data(data_shell *datash, char **av)
{
	unsigned int i;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	datash->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		datash->_environ[i] = _strdup(environ[i]);
	}

	datash->_environ[i] = NULL;
	datash->pid = aux_itoa(getpid());
}

/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	data_shell datash;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&datash, av);
	shell_loop(&datash);
	free_data(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}
/**
 * exit_shell - exits the shell
 *
 * @datash: data relevant (status and args)
 * Return: 0 on success.
 */
int exit_shell(data_shell *datash)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;

	if (datash->args[1] != NULL)
	{
		ustatus = _atoi(datash->args[1]);
		is_digit = _isdigit(datash->args[1]);
		str_len = _strlen(datash->args[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			get_error(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = (ustatus % 256);
	}
	return (0);
}

