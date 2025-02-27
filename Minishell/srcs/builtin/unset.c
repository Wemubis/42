/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:50:47 by wemubis_          #+#    #+#             */
/*   Updated: 2023/03/16 18:05:28 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	unset_values(char *variable)
// {
// 	/*Free la variables et tout ce qui est associe*/
// }

int	unset_main(int ac, char **av, char **env)
{
	int	i;

	i = 1;
	(void)env;
	(void)av;
	while (i < ac)
	{
		/* unset_values(av[i]); */
		i++;
	}
	return (0);
}
