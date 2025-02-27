/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:36:21 by wemubis_          #+#    #+#             */
/*   Updated: 2023/04/04 20:18:13 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	smallest(int actual, int new)
{
	if (actual < new)
		return (actual);
	return (new);
}

void	*ft_realloc(void *ptr, size_t actual_size, size_t new_size)
{
	void	*newptr;
	int		size;

	size = smallest(actual_size, new_size);
	newptr = malloc(size);
	newptr = ft_memcpy(newptr, ptr, size);
	free(ptr);
	return (newptr);
}
