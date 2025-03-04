/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:00:34 by wemubis_          #+#    #+#             */
/*   Updated: 2022/11/14 15:31:48 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s);
	if (!len && c != '\0')
		return (NULL);
	dst = (char *)s;
	while (len > 0)
	{
		if (dst[len] == (unsigned char)c)
			return (&dst[len]);
		len--;
	}
	if (len == 0 && dst[len] == (unsigned char)c)
		return (&dst[len]);
	return (NULL);
}
