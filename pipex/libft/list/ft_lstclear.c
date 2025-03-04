/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:37:11 by wemubis_          #+#    #+#             */
/*   Updated: 2022/11/16 18:22:16 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*adjacent;

	if (!lst || !del)
		return ;
	if (!*lst)
	{
		*lst = NULL;
		return ;
	}
	elem = *lst;
	while (elem)
	{
		adjacent = elem->next;
		ft_lstdelone(elem, del);
		elem = adjacent;
	}
	*lst = NULL;
}
