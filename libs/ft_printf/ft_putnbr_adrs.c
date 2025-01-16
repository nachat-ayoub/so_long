/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_adrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:37:24 by anachat           #+#    #+#             */
/*   Updated: 2024/11/21 16:44:02 by anachat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_adrs(unsigned long n, int *count)
{
	if (n < 16)
		ft_putchar("0123456789abcdef"[n], count);
	else
	{
		ft_putnbr_adrs(n / 16, count);
		ft_putnbr_adrs(n % 16, count);
	}
}
