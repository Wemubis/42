/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:56:27 by wemubis_          #+#    #+#             */
/*   Updated: 2022/07/27 20:10:23 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	while (ac != 1)
	{
		i = 0;
		while (av[ac - 1][i] != '\0')
		{
			ft_putchar(av[ac - 1][i]);
			i++;
		}
		ft_putchar('\n');
		ac--;
	}
	return (0);
}
