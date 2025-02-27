/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:09:40 by wemubis_          #+#    #+#             */
/*   Updated: 2022/11/23 16:57:45 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*------------INCLUD------------*/
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/*------------PROTOS------------*/
/*-----HEAD-----*/
char	*get_next_line(int fd);

/*-----HELP-----*/
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*keep_left(char *str);

#endif