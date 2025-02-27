/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis <wemubis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:53:29 by wemubis           #+#    #+#             */
/*   Updated: 2023/11/17 23:40:09 by wemubis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtn	exec_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (cd_main);
	if (ft_strcmp(cmd, "echo") == 0)
		return (echo_main);
	if (ft_strcmp(cmd, "env") == 0)
		return (env_main);
	if (ft_strcmp(cmd, "exit") == 0)
		return (exit_main);
	if (ft_strcmp(cmd, "export") == 0)
		return (export_main);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (pwd_main);
	if (ft_strcmp(cmd, "unset") == 0)
		return (unset_main);
	return (0);
}
