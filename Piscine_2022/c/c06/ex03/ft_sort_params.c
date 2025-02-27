/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:40:33 by wemubis_          #+#    #+#             */
/*   Updated: 2022/07/18 10:54:04 by wemubis_         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_params(int ac, char **av, int s)
{
	int		i;
	char	*tpmp;

	while (s != 0)
	{
		s = 0;
		i = 0;
		while (++i < ac - 1)
		{
			while (ft_strcmp(av[i], av[i + 1]) > 0)
			{
				tpmp = av[i];
				av[i] = av[i + 1];
				av[i + 1] = tpmp;
				s++;
			}
		}
	}
	i = 0;
	while (++i < ac)
	{
		ft_putstr(av[i]);
		ft_putchar('\n');
	}
}

int	main(int ac, char **av)
{
	int	s;

	s = -1;
	ft_sort_params(ac, av, s);
	return (0);
}
