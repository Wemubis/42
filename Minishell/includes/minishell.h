/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis <wemubis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:26:32 by wemubis_          #+#    #+#             */
/*   Updated: 2023/11/17 23:43:06 by wemubis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#define SIZE 1024

/*-------------------------HEAD-------------------------*/
# include "../libft/libft.h"
# include "struct.h"
# include <string.h>
# include <errno.h>
# include <stdio.h>

/*---------------V-GLOBAL---------------*/


/*-------------------------FCTN-------------------------*/

/*---------------BUILTIN---------------*/
t_builtn	exec_builtin(char *cmd);
int			cd_main(t_list ***env, t_cmd **cmd);
int			echo_main(int ac, char **av, char **env);
int			env_main(int ac, char **av, char **env);
int			exit_main(int ac, char **av, char **env);
int			export_main(int ac, char **av, char **env);
int			pwd_main(int ac, char **av, char** env);
int			unset_main(int ac, char **av, char **env);

/*----------------PARSING----------------*/
t_cmd		*parse_line(char *line);
int			split_line(t_list **list, char *line);
int			end_arg(char *str, int start);
int			check_quotes(char *line);
int			find_quotes_end(char *str, int len_arg);
int			index(char *str, char *to_find, int nb);
int			index_of_space(char *str);
int			cmd_creation(t_cmd **cmd_tab, t_list *list);
int			append_content(char *content, char ***tab_args);
int			infile_or_heredoc(t_list **list, char ***tab_in, char ***tab_here);
int			handle_outfiles(t_list **list, t_lstout **outfiles);

/*---------------EXEC-COMMAND---------------*/
void		exec_cmds(t_list **env, t_cmd *cmd);

/*---------------FREE-QUIT---------------*/
void		free_tab(char **tab);
void		clear_lstout(t_lstout **outfile);
void		free_cmds(t_cmd **cmd);
void		free_all(t_list	**env, t_cmd *cmd, char *line);
void		ft_quit(t_list	**env, t_cmd *cmd, int status);

/*---------------ENVIRONNEMENT---------------*/
void		dup_env(char **envp, t_list **env);

#endif