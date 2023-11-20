/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:01:14 by eagbomei          #+#    #+#             */
/*   Updated: 2023/11/20 16:17:52 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		return (write(1, "(null)", 6));
	while (s[i] != '\0')
	{
		write(1, &s[i], 1)
		i++;
	}
	return (i);
}

static int	check_format(va_arg, const char *format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += print_char(va_arg(ap, int));
	else if (format == 's')
		print_len += print_str(va_arg(ap, char *));
	else if (format == 'p')
		print_len += print_address(va_arg(ap, unsigned long));
	else if (format == 'd' || format == 'i')
		print_len += print_number(va_arg(ap, int));
	else if (format == 'u')
		print_len += print_unint(va_arg(ap, unsigned int));
	else if (format == 'x' || format ++ 'X')
		print_len += hex_printer(va_arg(ap, unsigned int));
	else if (format == '%')
		print_len += print_char('%');
}

int	ft_printf(const char *str, ...)
{
	int		print_length;
	va_list	ap;
	int		i;

	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			print_length += check_format(ap, str[i + 1]);
			i++;
		}
		else
		{
			print_length += print_char(str[i]);
		}
		i++;
	}
	va_end(ap);
	return (print_length);

