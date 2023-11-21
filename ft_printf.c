/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:01:14 by eagbomei          #+#    #+#             */
/*   Updated: 2023/11/21 18:10:55 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

int	print_str(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		return (6);
	}
	while (s[i] != '\0')
	{
		if (write(1, &s[i], 1) < 0)
			return (-1);
		i++;
	}
	return (i);
}

static int	check_format(va_list ap, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += print_char(va_arg(ap, int));
	else if (format == 's')
		print_len += ft_printstr(va_arg(ap, char *));
	else if (format == 'p')
		print_len += address_printer(va_arg(ap, unsigned long));
	else if (format == 'd' || format == 'i')
		print_len += ft_print_number(va_arg(ap, int));
	else if (format == 'u')
		print_len += print_unint(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		print_len += hex_printer(format, va_arg(ap, unsigned int));
	else if (format == '%')
		print_len += print_char('%');
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		print_length;
	va_list	ap;
	int		result;
	int		i;

	i = 0;
	print_length = 0;
	result = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			result = check_format(ap, str[i + 1]);
			if (result == -1)
				return (-1);
			i++;
			print_length += result;
		}
		else
		{
			result = print_char(str[i]);
			if (result == -1)
				return (-1);
			print_length += result;
		}
		i++;
	}
	va_end(ap);
	return (print_length);
}
/* 
#include <stdio.h>
int    main(void)
{
//     //int a = 50;
//     //int *h = &a;

   ft_printf("%u\n", 2523523523523532225);
ft_printf("%u\n", 0);
// int i = ft_printf("%p\n", NULL);
//int a = ft_printf("%x\n", -10);
// // //    ft_printf("%i\n", 30);
// //      ft_printf("%u\n", 10);
// //int i =    ft_printf("%x", 4294967295);
// //ft_printf("%X\n", 160);
// //    ft_printf("%u\n", -100);
// //    printf("%u\n", -100);
// ft_printf("\001\002\007\v\010\f\r\n");

//     printf("\001\002\007\v\010\f\r\n");
   printf("%u\n", 2523523523523532225);
//      int j =printf("%p\n", NULL); 
//     printf("%d\n", ft_printf("%s\n%c\n%d\n%i\n", "hello", 'G', 20, 30));
//int b = printf("%x\n", -10);
// //     printf("%u\n", );
// // int j = printf("%x", 42949672);
// //      printf("%X\n", 160);
//printf("a bytes: %d\nb bytes: %d\n", a, b);
// //     printf("%%\n", );
}
 */