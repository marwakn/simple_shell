#include "shell.h"

/**
  * _atoi - convert str to int
  * @s: the string
  *
  * Return: the number in integer
  */
int _atoi(char *s)
{
	unsigned int num = 0;
	int i = 0;
	int sign = 1;

	while (*(s + i))
	{
		if (*(s + i) == '-')
			sign *= -1;
		else if (*(s + i) >= '0' && *(s + i) <= '9')
			num = (num * 10) + (*(s + i) - '0');
		else if (num > 0)
			break;
		i++;
	}
	return ((num * sign));
}



/**
 * is_num - Checks if a string represents a numeric value
 * @str: The string to check
 * Return: True if the string is numeric, false otherwise
 */
bool is_num(const char *str)
{
	int i;

	if (str == NULL || *str == '\0')
		return (false);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}

	return (true);
}




/**
 * _strlen1 - Function that returns the length of a string
 * @str: Pointer to the string
 * Return: Length of the string
 */
size_t _strlen1(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * _snprintf - printd
 * @str: string
 * @size: size
 * @format: format
 * Return: Integer
*/
int _snprintf(char *str, size_t size, const char *format, ...)
{
	va_list args;
	int result;

	va_start(args, format);
	result = vsnprintf(str, size, format, args);
	va_end(args);

	return (result);
}
