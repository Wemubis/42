/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:00:47 by wemubis_          #+#    #+#             */
/*   Updated: 2022/07/17 14:03:36 by wemubis_         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		input_check(int argc, char **argv);

void	print_tab(char tab[4][4]);

int	main(int argc, char **argv)
{
	char	tab[4][4];
	int		i;
	int		j;

	i = 0;
	if (input_check(argc, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tab[i][j] = '0';
			j ++;
		}
		i++;
	}
	print_tab(tab);
	return (0);
}
