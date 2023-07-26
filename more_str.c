#include "shell.h"
/**
 * _strcpy - copie a string from src to dest
 * @source: src
 * @dest: destination
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *source)
{
	int i;

	for (i = 0; source[i] != '\0'; i++)
	{
		dest[i] = source[i];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _isalpha - check if the input is a letter
 * @c: c
 * Return: integer
 */
int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (SUCCESS);
	}
	return (FAIL);
}
