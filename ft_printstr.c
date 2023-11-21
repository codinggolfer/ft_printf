/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:19:46 by eagbomei          #+#    #+#             */
/*   Updated: 2023/11/21 18:09:33 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	print_lenght;

	print_lenght = 0;
	if (str == 0)
		return (print_str(0));
	print_lenght = print_str(str);
	return (print_lenght);
}
