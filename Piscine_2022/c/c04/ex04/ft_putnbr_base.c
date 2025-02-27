/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:51:51 by wemubis_          #+#    #+#             */
/*   Updated: 2022/07/28 17:59:05 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

long	ft_length_nbr(long b, long s)
{
	long	l;

	l = 1;
	if (b <= l)
		return (l);
	while (s != 0)
	{
		s /= b;
		l *= b;
	}
	l /= b;
	return (l);
}

long	ft_length_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_check(char *base, long b)
{
	int	j;
	int	i;

	i = 0;
	if (base[i] == '\0' || b == 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] <= ' ' || base[i] >= '~')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	l;
	long	s;
	int		b;

	b = ft_length_base(base);
	s = nbr;
	l = ft_length_nbr(b, s);
	if (ft_check(base, b) == 0)
		return ;
	if (s == 0)
		ft_putchar(base[0]);
	if (s < 0)
	{
		s *= (-1);
		ft_putchar('-');
	}
	while (l != 0)
	{
		ft_putchar(base[s / l]);
		s %= l;
		l /= b;
	}
}
