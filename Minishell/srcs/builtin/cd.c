/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:50:27 by wemubis_          #+#    #+#             */
/*   Updated: 2023/03/19 12:59:40 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_home_path(char **env)
{
	int	i;

	if (!env)
		return (NULL);
	i = -1;
	while (env[++i])
		if (!ft_strncmp(env[i], "HOME=", 5))
			if (env[i])
				return (env[i] + 5);
	return (NULL);
}

char	*from_tilde(char **env, char *after)
{
	char	*tilde;

	tilde = get_home_path(env);
	if (!tilde)
		return (NULL);
	if (!after[0])
		return (ft_strdup(tilde));
	return (ft_strjoin(tilde, after));
}

int	fail_chdir(char *path)
{
	ft_dprintf(1, "cd: %s: %s", strerror(errno), path);
	free(path);
	return (1);
}

int	cd_main(int ac, char **av, char **env)
{
	char	*path;

	path = NULL;
	if (ac > 2)
	{
		ft_dprintf(1, "Too many args for cd");
		return (1);
	}
	if (ac < 2)
		path = get_home_path(env);
	else if (av[1][0] == '~')
		path = from_tilde(env, &av[1][1]);
	else
		path = ft_strdup(av[1]);
	if (!path)
	{
		ft_dprintf(1, "Path error");
		return (1);
	}
	if (chdir(path) == -1)
		return (fail_chdir(path));
	free(path);
	return (0);
}
