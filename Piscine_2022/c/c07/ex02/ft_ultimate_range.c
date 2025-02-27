/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:49:48 by wemubis_          #+#    #+#             */
/*   Updated: 2022/07/28 19:32:59 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	j;
	int	*tab;

	i = 0;
	j = min;
	if (min >= max)
	{
		tab = ((void *) 0);
		return (0);
	}
	else
		tab = (int *)malloc(sizeof(int) * (max - min));
	while (i < (max - min))
	{
		tab[i] = j;
		j++;
		i++;
	}
	*range = tab;
	return (i);
}
