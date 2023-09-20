#include <unistd.h>
#include "main.h"

/**
 * _putchar - Write a character to the standard output
 * @c: The character to write
 * Return: The number of characters written (1) on success, -1 on error
 */
int _putchar(char c)
		{
		if (write(1, &c, 1) == -1)
		{
		return (-1);
		}
		return (1);
		}
