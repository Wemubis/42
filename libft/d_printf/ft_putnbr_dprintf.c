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

#include "../libft.h"

static long	len_nb(int n)
{
	long	len;

	len = 1;
	n /= 10;
	while (n)
	{
		len *= 10;
		n /= 10;
	}
	return (len);
}

int	ft_putnbr_dprintf(int n, int fd)
{
	long	nb;
	int		len;
	int		ret;

	len = len_nb(n);
	nb = n;
	ret = 0;
	if (nb == 0)
		return (write(fd, "0", 1));
	if (nb < 0)
	{
		nb *= -1;
		ret += write(fd, "-", 1);
	}
	while (len)
	{
		ft_putchar_fd(nb / len + '0', fd);
		nb %= len;
		len /= 10;
		ret++;
	}
	return (ret);
}
