/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:19:47 by wemubis_          #+#    #+#             */
/*   Updated: 2022/07/10 17:16:54 by wemubis_         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

long	ft_length(long nb);

void	ft_putnbr(int nb)
{
	long	longueur;
	long	save;

	save = nb;
	longueur = ft_length(save) / 10;
	if (save == 0)
	{
		ft_putchar(save + 48);
	}
	if (save < 0)
	{
		save *= (-1);
		ft_putchar('-');
	}
	while (longueur != 0)
	{
		ft_putchar(save / longueur + 48);
		save %= longueur;
		longueur /= 10;
	}
}

long	ft_length(long nb)
{
	long	longueur;

	longueur = 1;
	while (nb != 0)
	{
		nb /= 10;
		longueur *= 10;
	}
	return (longueur);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
