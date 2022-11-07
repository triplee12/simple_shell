#include "main.h"

/**
 * _strcmp - Compares pointers to two strings.
 * @s1: A pointer to the first string to be compared.
 * @s2: A pointer to the second string to be compared.
 *
 * Return: If str1 < str2, the negative difference of
 * the first unmatched characters.
 *         If s1 == s2, 0.
 *         If s1 > s2, the positive difference of
 *         the first unmatched characters.
 */

int _strcmp(char *s1, char *s2)
{
	while ((*s1 && *s2) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * _strcpy - copies one string into another
 * @str1: First string, copied into
 * @str2: Second string, copied from
 * @s: Integer size of first strings memory in bytes.
 *
 * Return: 1 if the copy succeeded or 0 if it failed.
 */

int _strcpy(char *str1, char *str2, int s)
{
	int i = 0, j = 0;

	while (str2[j])
		j++;

	if (j < s)
	{
		while (str2[i])
			str1[i] = str2[i];
		str1[i] = '\0';
		return (0);
	}

	return (1);
}
