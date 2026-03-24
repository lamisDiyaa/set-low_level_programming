#include "main.h"

/**
 * _strncpy - copies a string
 * @dest: destination string
 * @src: source string
 * @n: number of bytes to copy
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int j;

	j = 0;
	/* بننقل الحروف من src لـ dest بحد أقصى n */
	while (j < n && src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	/* لو لسه مخلصناش الـ n، بنملى الباقي أصفار (null bytes) */
	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}

	return (dest);
}
