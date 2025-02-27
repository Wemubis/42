/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis <wemubis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:50:04 by wemubis_          #+#    #+#             */
/*   Updated: 2023/11/17 23:38:55 by wemubis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmds(t_list **env, t_cmd *cmd)
{
	t_builtn	builtin;


	while (cmd != NULL)
	{
		builtin = exec_builtin(cmd->tab_args[0]);
		// else if (is_relative_path(cmd->cmd[0]))
			// fork_cmd(tcsh, cmd, cmd->cmd[0]);
		// else
			// find_and_fork_cmd(tcsh, cmd);
		// tcsh->var.return_value = cmd->rtn;
		cmd = cmd->next;
	}
}