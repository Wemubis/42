/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:13:12 by wemubis_          #+#    #+#             */
/*   Updated: 2022/11/29 16:24:50 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_length_nbr(uintptr_t nb, int len_b)
{
	long	l;

	l = 1;
	nb /= len_b;
	while (nb)
	{
		nb /= len_b;
		l *= len_b;
	}
	return (l);
}

int	ft_putptr_base(void *n, char *base)
{
	size_t		len;
	int			len_b;
	int			ret;
	uintptr_t	nb;

	nb = (uintptr_t)n;
	len_b = ft_strlen(base);
	len = ft_length_nbr(nb, len_b);
	ret = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	while (len)
	{
		ft_putchar(base[nb / len]);
		nb %= len;
		len /= len_b;
		ret++;
	}
	return (ret);
}
