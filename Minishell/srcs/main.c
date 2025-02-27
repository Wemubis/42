/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:26:36 by wemubis_          #+#    #+#             */
/*   Updated: 2023/11/11 16:48:38 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_cmd	*cmd;
	t_list	*top_envp;

	(void)ac;
	(void)av;
	top_envp = NULL;
	dup_env(env, &top_envp);
	while (1)
	{
		line = readline("mini$> ");
		if (!line)
			ft_quit(&top_envp, cmd, 0);
		cmd = parse_line(line);
		if (!cmd)
			continue ;
		free(line);
		exec_cmds(&top_envp, cmd);
		free_cmds(&cmd);
	}
	return (free_all(&top_envp, cmd, line), 0);
}
