#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: difference between characters
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	/* بنمشي طول ما الحروف متساوية ومش null */
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}

	/* بنرجع الفرق بين الحرفين اللي وقفنا عندهم */
	return (s1[i] - s2[i]);
}
