/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:57:25 by wemubis_          #+#    #+#             */
/*   Updated: 2022/07/28 20:04:13 by wemubis_         ###   ########.fr       */
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

int	ft_check_base(char *base, long l)
{
	int	j;
	int	i;

	i = 0;
	if (base[i] == '\0' || l <= 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] <= ' ' || base[i] >= '~')
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

int	ft_atoi_base(char *nbr, char *base_from)
{
	long	n;
	int		signe;
	int		i;
	int		l;

	n = 0;
	i = 0;
	l = ft_lenb(base_from);
	signe = 1;
	while (space(nbr[i]))
		i++;
	while ((nbr[i] == '+') || (nbr[i] == '-'))
	{
		if (nbr[i] == '-')
			signe *= -1;
		i++;
	}
	while (ft_base(nbr[i], base_from) != -1)
	{
		n = n * l + ft_base(nbr[i], base_from);
		i++;
	}
	return (n * signe);
}
