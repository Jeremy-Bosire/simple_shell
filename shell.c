#include "main.h"

/**
 * main - A simple UNIX command-line interpreter.
 * Return: Always 0(Success)
 */
int main(void)
{
	pid_t q;
	size_t n = 10;
	char *buf;
	char *argVec[] = {NULL};

	printf("#cisfun$ ");
	while (getline(&buf, &n, stdin) != EOF)
	{
		buf[strcspn(buf, "\n")] = '\0';
		q = fork();
		if (q == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (q == 0)
		{
			if (execvp(buf, argVec) == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
			printf("#cisfun$ ");
		}
	}
	free(buf);
	return (0);
}
