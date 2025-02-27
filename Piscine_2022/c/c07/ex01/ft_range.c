/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:53:21 by wemubis_          #+#    #+#             */
/*   Updated: 2022/07/18 22:19:40 by wemubis_         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	l;
	int	i;
	int	*tab;

	i = 0;
	l = max - min;
	if (min >= max)
		return (NULL);
	tab = malloc(l * sizeof(int));
	if (tab == NULL)
		return (NULL);
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}
