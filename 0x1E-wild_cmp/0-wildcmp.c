#include "holberton.h"

/**
 * wildcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * special character * can replace any character
 * including empty string
 * Return: 1 if match, 0 if not
 */
int wildcmp(char *s1, char *s2)
{
	int i, j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && s2[j] != '\0')
	{
		if (s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else if (s2[j] == '*')
		{
			j++;
			while (s2[j] == '*')
				j++;
			while (s1[i] != s2[j] && s1[i] != '\0')
				i++;
		}
		else
			return (0);
	}
	if (s1[i] == '\0' && s2[j] == '\0')
		return (1);
	if (s2[j] == '\0' && s1[i] != '\0')
		return (0);
	if (s2[j] == '\0' && s1[i] == '\0')
		return (1);
	return (0);
}
