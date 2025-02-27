/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:51:29 by wemubis_          #+#    #+#             */
/*   Updated: 2022/07/07 12:51:44 by wemubis_         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_numbers(char x, char y);

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a <= 98)
	{
		while (b <= 99)
		{
			ft_numbers(a, b);
			b++;
		}
		a++;
		b = a + 1;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_numbers(char x, char y)
{
	ft_putchar((x / 10) + 48);
	ft_putchar((x % 10) + 48);
	ft_putchar(' ');
	ft_putchar((y / 10) + 48);
	ft_putchar((y % 10) + 48);
	if (!(x == 98 && y == 99))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}
