/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:00:03 by wemubis_          #+#    #+#             */
/*   Updated: 2023/11/05 23:54:44 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_line_space(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (!ft_isspace(line[i]))
			return (0);
	return (1);
}

t_cmd	*parse_line(char *line)
{
	t_list	*list;
	t_cmd	*cmd_lst;

	if (ft_line_space(line) || !check_quotes(line) || !split_line(&list, line))
		return (NULL);
	if (check_meta_char(list) || !cmd_creation(&cmd_lst, list))
		return (ft_lstclear(&list), NULL);
	ft_lstclear(&list);
	return (cmd_lst);
}
