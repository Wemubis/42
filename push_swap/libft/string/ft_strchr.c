/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:38:11 by wemubis_          #+#    #+#             */
/*   Updated: 2022/11/18 16:35:33 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = (char *)s;
	while (i < ft_strlen(dst))
	{
		if (dst[i] == (unsigned char)c)
			return (&dst[i]);
		i++;
	}
	if (!dst[i] && c == '\0')
		return (&dst[i]);
	return (NULL);
}
