#include "main.h"

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

	(void) ac;
	(void) av;

	signal(SIGINT, get_sigint);
	shell_loop();
	return (0);
}
/**
 * exit_shell - exits the shell
 *
 * @args: arguments.
 * Return: 0 on success.
 */
int exit_shell(char **args)
{
	(void) args;
	return (0);
}
