/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:35:34 by wemubis_          #+#    #+#             */
/*   Updated: 2022/11/29 13:42:32 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	len_nb(int nb)
{
	long	len;

	len = 1;
	while (nb)
	{
		len *= 10;
		nb /= 10;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		len;
	int		ret;

	len = len_nb(n) / 10;
	nb = n;
	ret = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	if (nb < 0)
	{
		nb *= -1;
		ret += write(1, "-", 1);
	}
	while (len)
	{
		ft_putchar(nb / len + '0');
		nb %= len;
		len /= 10;
		ret++;
	}
	return (ret);
}
