/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 01:17:34 by wemubis_          #+#    #+#             */
/*   Updated: 2022/07/15 03:51:30 by wemubis_         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	l;

	i = 0;
	l = 0;
	if (size != 0)
	{
		while (src[i] != '\0')
		{
			if (i < (size - 1))
			{
				dest[i] = src[i];
				l++;
			}
			i++;
		}
	}
	else
	{
		while (src[i] != '\0')
			i++;
	}
	dest[l] = '\0';
	return (i);
}
