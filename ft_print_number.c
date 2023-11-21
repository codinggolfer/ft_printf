/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:26:47 by eagbomei          #+#    #+#             */
/*   Updated: 2023/11/21 18:14:22 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_number(int i)
{
	int		print_lenght;
	char	*number;

	print_lenght = 0;
	number = ft_itoa(i);
	if (number == 0)
	{
		free(number);
		return (-1);
	}
	print_lenght += print_str(number);
	free(number);
	return (print_lenght);
}
