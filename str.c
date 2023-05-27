#include "shell.h"

/**
 * _strncmp - Function that compares two strings
 * @s1: Pointer to the first string
 * @s2: Pointer to the second string
 * @n: Number of characters to compare
 * Return:
 *   - an integer less than, equal to,
 *     of `s1` are respectively less than, equal to,
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] == '\0' || s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

/**
 * _strcmp - compares two strings.
 * @s1: First string
 * @s2: Second string
 * Return: s1[i] - s2[i]
 */


int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
		{
			return (0);
		}
		i++;

	}
	return (s1[i] - s2[i]);
}


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strlen - returns the length of a string
 * @s: the pointer of the string
 *
 * Return: len
 */

int _strlen(char *s)
{
	int len = 0;
	int i = 0;

	while (*(s + i) != '\0')
	{
		len++;
		i++;
	}

	return (len);
}

