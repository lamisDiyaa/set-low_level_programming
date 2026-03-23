#include "main.h"

/**
 * print_rev - prints a string, in reverse, followed by a new line
 * @s: string to print
 *
 * Return: void
 */
void print_rev(char *s)
{
	int len = 0;
	int i;

	/* بنعد الحروف عشان نعرف الـ String آخره فين */
	while (s[len] != '\0')
	{
		len++;
	}

	/* بنبدأ من آخر حرف (قبل الـ Null) ونرجع لورا */
	for (i = len - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
