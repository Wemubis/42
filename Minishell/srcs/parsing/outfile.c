/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:02:32 by wemubis_          #+#    #+#             */
/*   Updated: 2023/11/10 23:15:15 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_lstout	*outlst_new(char *file, int todo)
{
	t_lstout	*new;

	new = malloc(sizeof(t_lstout));
	if (!new)
		return (0);
	new->file = ft_strdup(file);
	if (!new->file)
		return (free(new), 0);
	new->todo = todo;
	new->next = NULL;
	return (new);
}

static t_lstout	*last(t_lstout *list)
{
	if (list)
		while (list->next)
			list = list->next;
	return (list);
}

static int	append_lstout(t_lstout **outfile, char *file, int len)
{
	t_lstout	*tmp;
	int			todo;

	todo = WRITE;
	if (len == 2)
		todo = APPEND;
	tmp = outlst_new(file, todo);
	if (!tmp)
		return (0);
	if (!(*lst))
		(*lst) = tmp;
	else
		last(*lst)->next = tmp;
	return (1);
}

int	handle_outfiles(t_list **list, t_lstout **outfile)
{
	int		len;
	char	*content;

	content = (*list)->content;
	len = ft_strlen(content);
	if (!(*list))
		return (1);
	if ((len == 1 && !ft_strncmp(content, ">", len))
		|| (len == 2 && !ft_strncmp(content, ">>", len)))
	{
		*list = (*list)->next;
		if (*list
			&& ((len == 1 && !append_lstout(outfile, content, len))
			|| (len == 2 && !append_lstout(outfile, content, len))))
			return (0);
		*list = (*list)->next;
	}
	return (1);
}