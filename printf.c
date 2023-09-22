#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


/**
 * _printf - Produces output according to a format.
 * @format: A character string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;


	va_start(args, format);


	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);


				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					write(1, str, 1);
					str++;
					count++;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				int digits = 0;
				int temp = num;
				char *num_str;
				int i;


				if (num < 0)
				{
					write(1, "-", 1);
					count++;
					temp = -temp;
				}


				while (temp != 0)
				{
					temp /= 10;
					digits++;
				}


				num_str = malloc((digits +1) * sizeof(char));


				for ( i = digits - 1; i >= 0; i--)
				{
					num_str[i] = (num % 10) + '0';
					num /= 10;
				}


				write(1, num_str, digits);
				count += digits;


				free(num_str);
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				count++;
			}
		}
		else
		{
			write(1, format, 1);
			count++;


		}


		format++;
	}


	va_end(args);


	return (count);
}
