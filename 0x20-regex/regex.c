#include "regex.h"

/**
 * match_star - Match a string with a regex
 * @str: String to match
 * @pattern: Regex to match
 *
 * Return: 1 if match, 0 otherwise
 */
int match_star(char const *str, char const *pattern)
{
	if (!*str && !*pattern)
		return (1);

	if (!*pattern)
		return (1);

	if (!*str)
		return (0);

	if (*str == *pattern || (*pattern == '.' && *str))
		return (match(str + 1, pattern) || match(str, pattern + 1));

	return (match(str, pattern + 1));
}

/**
 * match - Match a string with a regex
 * @str: String to match
 * @pattern: Regex to match
 *
 * Return: 1 if match, 0 otherwise
 */
int match(char const *str, char const *pattern)
{
	if (!*pattern)
		return (!*str);

	if (*pattern == '*')
		return (match_star(str, pattern + 1));

	if (!*str)
		return (0);

	if (*str == *pattern || (*pattern == '.' && *str))
		return (match(str + 1, pattern + 1));

	return (0);
}

/**
 * regex_match - Match a string with a regex
 * @str: String to match
 * @pattern: Regex to match
 *
 * Return: 1 if match, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	if (!str || !pattern)
		return (0);

	return (match(str, pattern));
}
