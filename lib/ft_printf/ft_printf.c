/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:36:51 by anachat           #+#    #+#             */
/*   Updated: 2024/11/20 16:36:51 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_format(char sp, va_list args, int *count)
{
	if (sp == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (sp == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (sp == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (sp == 'd')
		ft_putnbr(va_arg(args, int), count);
	else if (sp == 'u')
		ft_putnbr_uns(va_arg(args, unsigned int), count);
	else if (sp == 'x' || sp == 'X')
		ft_putnbr_hex(va_arg(args, unsigned int), count, sp);
	else if (sp == 'p')
	{
		ft_putstr("0x", count);
		ft_putnbr_adrs(va_arg(args, unsigned long), count);
	}
	else
		ft_putchar(sp, count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	size_t	i;

	if (write(1, "", 0) == -1)
		return (-1);
	va_start(args, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '\0')
				break ;
			print_format(s[i], args, &count);
		}
		else
			ft_putchar(s[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
