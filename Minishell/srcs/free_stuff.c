/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:23:01 by wemubis_          #+#    #+#             */
/*   Updated: 2023/11/13 11:47:06 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	tab = NULL;
}

void	clear_lstout(t_lstout **outfile) {
	t_lstout	tmp;

	while (*outfile)
	{
		tmp = (*outfile)->next;
		free((*outfile)->file);
		(*outfile) = tmp;
	}
	(*outfile) = NULL;
}

void	free_cmds(t_cmd **cmd)
{
	t_cmd	*tmp;

	while (*cmd)
	{
		tmp = (*cmd)->next;
		// add all the necessarie lines later
		free((*cmd)->content);
		free_tab((*cmd)->tab_args);
		free_tab((*cmd)->infiles);
		free_tab((*cmd)->heredocs);
		clear_lstout(&(*cmd)->outfiles);
		free((*cmd));
		(*cmd) = tmp;
	}
	*cmd = NULL;
}

void	free_all(t_list	**env, t_cmd *cmd, char *line)
{
	rl_clear_history();
	ft_lstclear(env);
	free_cmds(&cmd);
	free(line);
}

void	ft_quit(t_list	**env, t_cmd *cmd, int status)
{
	rl_clear_history();
	ft_lstclear(env);
	free_cmds(&cmd);
	ft_printf("exit\n");
	exit(status);
}