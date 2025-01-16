/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:37:31 by anachat           #+#    #+#             */
/*   Updated: 2024/11/21 15:12:51 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(unsigned int n, int *count, char sp)
{
	if (n < 16)
	{
		if (sp == 'x')
			ft_putchar("0123456789abcdef"[n], count);
		else
			ft_putchar("0123456789ABCDEF"[n], count);
	}
	else
	{
		ft_putnbr_hex(n / 16, count, sp);
		ft_putnbr_hex(n % 16, count, sp);
	}
}
