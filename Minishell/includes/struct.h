/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis <wemubis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:26:29 by wemubis_          #+#    #+#             */
/*   Updated: 2023/11/17 23:37:31 by wemubis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*---------------PARSING---------------*/
enum {
	OTHER,
	OR,
	AND,
	PIPE,
};

enum {
	WRITE,
	APPEND,
};

typedef struct s_lstout
{
	char			*file;
	int				todo;
	struct s_lstout	*next;
}	t_lstout;

typedef struct s_cmd
{
	char			*content;
	char			**tab_args;
	char			**infiles;
	char			**heredocs;
	t_lstout		*outfiles;
	int				type_next;
	struct s_cmd	*next;
} t_cmd;

typedef int	(*t_builtn)(t_list **, t_cmd **);

#endif