/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:39:57 by wemubis_          #+#    #+#             */
/*   Updated: 2022/07/06 16:40:09 by wemubis_         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i = 78;
		ft_putchar(i);
	}
	else
	{
		i = 80;
		ft_putchar(i);
	}
}
