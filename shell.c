#include "main.h"

/**
 * main - A simple UNIX command-line interpreter.
 * Return: Always 0(Success)
 */
int main(void)
{
	pid_t q;
	size_t n = 10;
	char *argVec[] = {NULL};

	printf("#cisfun$ ");
	while (getline(&argVec[0], &n, stdin) != EOF)
	{
		argVec[0][strcspn(argVec[0], "\n")] = '\0';
		q = fork();
		if (q == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (q == 0)
		{
			if (execvp(argVec[0], argVec) == -1)
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
	free(argVec[0]);
	return (0);
}
