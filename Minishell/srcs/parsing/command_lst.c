/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:18:44 by wemubis_          #+#    #+#             */
/*   Updated: 2023/11/11 16:13:17 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*init_cmd(void)
{
	t_cmd	*tmp;

	tmp = malloc(sizeof(t_cmd));
	if (!tmp)
		return (0);
	// INIT toutes les valeurs une fois struct finito
	tmp->content = NULL;
	tmp->tab_args = NULL;
	tmp->infiles = NULL;
	tmp->outfiles = NULL;
	tmp->heredocs = NULL;
	tmp->type_next = OTHER;
	tmp->next = NULL;
	return (tmp);
}

static t_cmd	*last(t_cmd *list)
{
	while (list && list->next)
			list = list->next;
	return (list);
}

static int	type(char *str)
{
	if (!ft_strcmp(str, "|"))
		return (PIPE);
	if (!ft_strcmp(str, "||"))
		return (OR);
	if (!ft_strcmp(str, "&&"))
		return (AND);
	return (OTHER);
}

static int	append_cmd(t_list **list, t_cmd *tmp)
{
	while (*list && !type((*list)->content))
	{
		if (!handle_outfiles(list, &(tmp->outfiles)))
			return (0);
		else if (!infile_or_heredoc(list, &(tmp->infiles), &(tmp->heredocs)))
			return (0);
		if ((*list) && !is_sep((*list)->content))
		{
			if (!append_content((*list)->content), &(tmp->tab_args))
				return (0);
			*list = (*list)->next;
		}
	}
	return (1);
}

int	cmd_creation(t_cmd **cmd_lst, t_list *list)
{
	t_cmd	*tmp;

	cmd_lst = NULL;
	while (list)
	{
		tmp = init_cmd();
		if (!tmp)
			return (free_cmds(cmd_lst), 0);
		if (*cmd_lst)
			last(*cmd_lst)->next = tmp;
		else
			*cmd_lst = tmp;
		tmp->content = ft_strdup(list->content);
		if (!tmp->content || !append_cmd(&list, tmp))
			return (free_cmds(cmd_lst), 0);
		if (list)
		{
			tmp->type_next = type(list->content);
			list = list->next;
		}
	}
	return (1);
}
