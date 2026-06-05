#include <stdio.h>

void first(void) __attribute__ ((constructor));

/**
 * first - function that prints a message before main is executed
 *
 * Return: nothing
 */
void first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
