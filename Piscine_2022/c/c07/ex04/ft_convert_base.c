/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:57:20 by wemubis_          #+#    #+#             */
/*   Updated: 2022/07/28 19:03:15 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_check_base(char *base, long l);
long	ft_lenb(char *base);
int		ft_atoi_base(char *nbr, char *base_from);

long	ft_len(int b, int nbr)
{
	long	l;

	l = 1;
	if (b <= l)
		return (l);
	while (nbr != 0)
	{
		nbr /= b;
		l *= b;
	}
	l /= b;
	return (l);
}

int	ft_check(char *base, long l)
{
	int	j;
	int	i;

	i = 0;
	if (base[i] == '\0' || l == 1)
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

char	*ft_putnbr_base(int nbr, char *base)
{
	int		l;
	char	*tab;
	int		i;

	i = 0;
	l = ft_len(ft_lenb(base), nbr);
	tab = malloc(sizeof(char) * l + 2);
	if (tab == NULL)
		return (NULL);
	if (nbr == 0)
		tab[i++] = '0';
	if (nbr < 0)
	{
		nbr *= -1;
		tab[i++] = '-';
	}
	while (l != 0)
	{
		tab[i++] = base[nbr / l];
		nbr %= l;
		l /= ft_lenb(base);
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!(ft_check(base_from, ft_lenb(base_from))))
		return (NULL);
	if (!(ft_check_base(base_to, ft_lenb(base_to))))
		return (NULL);
	return (ft_putnbr_base(ft_atoi_base(nbr, base_from), base_to));
}
