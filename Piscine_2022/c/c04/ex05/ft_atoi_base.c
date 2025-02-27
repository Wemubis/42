/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:18:37 by wemubis_          #+#    #+#             */
/*   Updated: 2022/07/28 20:01:16 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_lenb(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	space(char str)
{
	if (str == ' ' || str == '\f' || str == '\n'
		|| str == '\t' || str == '\v' || str == '\r')
		return (1);
	return (0);
}

int	ft_base(int c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
		if (base == '\0')
			return (-1);
	}
	return (-1);
}

int	ft_check(char *base, long b)
{
	int	j;
	int	i;

	i = 0;
	if (base[i] == '\0' || b <= 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] <= ' ' || base[i] >= '~')
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *nbr, char *base)
{
	long	n;
	int		signe;
	int		i;

	n = 0;
	i = 0;
	signe = 1;
	if (!(ft_check(base, ft_lenb(base))))
		return (0);
	while (space(nbr[i]))
		i++;
	while ((nbr[i] == '+') || (nbr[i] == '-'))
	{
		if (nbr[i] == '-')
			signe *= -1;
		i++;
	}
	while (ft_base(nbr[i], base) != -1)
	{
		n = n * ft_lenb(base) + ft_base(nbr[i], base);
		i++;
	}
	return (n * signe);
}
