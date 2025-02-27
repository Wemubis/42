/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:28:59 by wemubis_          #+#    #+#             */
/*   Updated: 2022/07/28 19:38:29 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

int	ft_lenlen(char *sep, char **strs, int size)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (i < size)
	{
		l += ft_len(strs[i]);
		i++;
	}
	l = l + ft_len(sep) * (size - 1) + 1;
	return (l);
}

char	*ft_meow(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;
	int		l;

	i = 0;
	if (size == 0)
	{
		dest = malloc(sizeof(char));
		*dest = 0;
		return (dest);
	}
	l = ft_lenlen(sep, strs, size);
	dest = malloc(l * sizeof(char));
	if (dest == NULL)
		return (NULL);
	*dest = 0;
	while (i < size)
	{
		ft_meow(dest, strs[i]);
		if (i < size - 1)
			ft_meow(dest, sep);
		i++;
	}
	return (dest);
}
