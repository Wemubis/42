/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:57:13 by wemubis_          #+#    #+#             */
/*   Updated: 2023/11/08 23:01:24 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_sep(char *str)
{
	if (!ft_strcmp(str, "|") || !ft_strcmp(str, "&"))
		return (1);
	if (!ft_strcmp(str, ">") || !ft_strcmp(str, "<"))
		return (1);
	if (!ft_strcmp(str, "<<") || !ft_strcmp(str, ">>"))
		return (1);
	return (0);
}

/*
	Return 1 on syntax error, 0 if there is no error
	Error :	A special is followed by a special
			The command ends with a special

	E.g.:	echo 42 > && cat Makefile
			echo 42 &&
*/
int	check_meta_char(t_list *list)
{
	t_list	*tmp;
	int		meta_char;

	tmp = list;
	meta_char = 0;
	while (tmp)
	{
		if (is_sep(tmp->content) && meta_char)
		{
			ft_dprintf(1, "%sminishell: parse error near %s", RED, tmp->content);
			return (1);
		}
		else if (is_sep(tmp->content))
			meta_char = 1;
		else
			meta_char = 0;
		if (!tmp->next && is_sep(tmp->content))
		{
			ft_dprintf(1, "%sminishell: the command cannot end with %s", RED, tmp->content);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
