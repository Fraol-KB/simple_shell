#include "main.h"

/**
 * get_builtin - builtin that pais the command in the arg
 * @cmd: command
 * Return: function pointer of the builtin command
 *
 */

int (*get_builtin(char *cmd))(char **args))
{
	builtin_t args[] = {
		{ "cd", get_cd },
		{ "env", get_env },
		{ "setenv", get_setenv },
		{ "unsetenv", get_unsetenv },
		{ "exit", get_exit },
		{ "alias", get_alias },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; args[i].name; i++)
	{
		if (_strcmp(args[i].name, command) == 0)
			break;
	}
	return (args[i].f);
}

/**
 * exec_line - finds builtins and commands
 *
 * @args: arguments
 * @input: input arguments
 * Return: 1 on success.
 */
int exec_line(char **args, char *input)
{
	int (*builtin)(char **args);

	if (args[0] == NULL)
		return (1);

	builtin = get_builtin(args[0]);

	if (builtin != NULL)
		return (builtin(args));

	return (cmd_exec(args, input));
}
