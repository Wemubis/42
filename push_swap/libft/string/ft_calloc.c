/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:10:43 by wemubis_          #+#    #+#             */
/*   Updated: 2022/11/18 16:41:59 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*dst;

	if (size && count >= SIZE_MAX / size)
		return (NULL);
	dst = malloc(count * size);
	if (!dst)
		return (NULL);
	ft_memset(dst, '\0', count * size);
	return (dst);
}
