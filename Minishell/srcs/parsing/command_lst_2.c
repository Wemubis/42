/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_lst_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:42:44 by wemubis_          #+#    #+#             */
/*   Updated: 2023/11/10 23:32:18 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**copy_content_arr(char *content, char ***tab_args, char **new_tab)
{
	int	i;

	i = 0;
	while ((*tab_args) && (*(tab_args)[i]))
	{
		new_tab[i] = ft_strdup((*tab_args)[i]);
		if (!new_tab[i])
			return (free_tab_n(), NULL);
		i++;
	}
	new_tab[i] = ft_strdup(content);
	if (!new_tab[i])
		return (free_tab_n(), NULL);
	i++;
	new_tab[i] = 0;
	return (new_tab);
}

int	append_content(char *content, char ***tab_args)
{
	char	**new_tab;
	int		len;

	len = arr_len(*tab_args) + 1; //len of *tab_array
	new_tab = malloc(sizeof(char *) * (len + 1));
	if (!new_tab)
		return (0);
	new_tab = copy_content_arr(content, tab_args, new_tab);
	if (!new_tab)
		return (free_arr(), 0);
	free_tab(*tab_args);
	*tab_args = new_tab;
	return (1);
}

int	infile_or_heredoc(t_list **list, char ***tab_in, char ***tab_here)
{
	int		len;
	char	*content;

	content = (*list)->content;
	len = ft_strlen(content);
	if (!(*list))
		return (1);
	if ((len == 1 && !ft_strncmp(content, "<", len))
		|| (len == 2 && !ft_strncmp(content, "<<", len)))
	{
		*list = (*list)->next;
		if (*list && ((len == 1 && !append_content(content, tab_in))
			|| (len == 2 && !append_content(content, tab_here))))
			return (0);
		*list = (*list)->next;
	}
	return (1);
}
