/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:54:35 by wemubis_          #+#    #+#             */
/*   Updated: 2022/11/14 13:06:47 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	unsigned char	ch;

	ch = (unsigned char)c;
	ps = (unsigned char *)s;
	while (n)
	{
		if (*ps == ch)
			return (ps);
		ps++;
		n--;
	}
	return (NULL);
}
