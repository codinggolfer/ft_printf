/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:56:15 by eagbomei          #+#    #+#             */
/*   Updated: 2023/11/22 18:19:33 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		print_str(char *s);
int		print_char(int c);
int		ft_print_number(int i);
char	*ft_itoa(int n);
int		print_unint(unsigned int i);
int		address_printer(uintptr_t i);
int		hex_printer(const char format, unsigned int i);

#endif