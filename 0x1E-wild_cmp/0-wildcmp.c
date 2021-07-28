#include "holberton.h"
#include <stdio.h>
/**
 * compare - Function that compares if strings s1 and s2 are the same.
 * @s1: First string
 * @s2: Second string
 * @ast: Number of asterisks counted in s2.
 *
 * Return: 1 if both are the same, 0 if not, -1 if error.
*/
int compare(char *s1, char *s2, int ast)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s2 == '*')
		return (compare(s1, s2 + 1, ++ast));
	else if (*s1 != *s2 && ast > 0)
	{
		if (*s1 != '\0')
			return (compare(s1 + 1, s2, ast));
		return (0);
	}
	else if (*s1 != *s2 && ast == 0)
		return (0);
	else if (*s1 == *s2 && ast > 0)
	{
		if (compare(s1 + 1, s2 + 1, 0) == 1)
			return (compare(s1 + 1, s2 + 1, ast));
		return (compare(s1 + 1, s2, ast));
	}
	else if (*s1 == *s2 && ast == 0)
		return (compare(s1 + 1, s2 + 1, 0));
	return (-1);
}


/**
* wildcmp - Functio to determine if 2 strings are equivalent.
* @s1: First string.
* @s2: Second string.
*
* Return: returns 1 if the strings can be
* considered identical, otherwise returns 0.
*/
int wildcmp(char *s1, char *s2)
{
	int ast = 0;

	return (compare(s1, s2, ast));
}
