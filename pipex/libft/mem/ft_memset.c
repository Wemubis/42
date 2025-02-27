/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:11:29 by wemubis_          #+#    #+#             */
/*   Updated: 2022/11/09 16:57:28 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ps;

	ps = (unsigned char *)b;
	while (len > 0)
	{
		*ps = c;
		ps++;
		len--;
	}
	return (b);
}
