/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:09:35 by wemubis_          #+#    #+#             */
/*   Updated: 2022/11/23 17:14:05 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

static char	*keep_right(char *string)
{
	char	*dst;
	int		i;
	int		j;

	if (!string)
		return (NULL);
	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (!string[i])
		return (free(string), NULL);
	dst = malloc(sizeof(char) * (ft_strlen(string) - i + 1));
	if (!dst)
		return (free(string), NULL);
	j = 0;
	i++;
	while (string[i])
		dst[j++] = string[i++];
	dst[j] = '\0';
	if (!dst[0])
		return (free(string), free(dst), NULL);
	return (free(string), dst);
}

static char	*read_save_string(int fd, char *string, int rt)
{
	char	*buff;
	char	*stash;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (free(string), NULL);
	while (rt > 0 && !ft_strchr(string, '\n'))
	{
		rt = read(fd, buff, BUFFER_SIZE);
		if (rt == -1)
			return (free(buff), free(string), NULL);
		if (rt == 0)
			break ;
		buff[rt] = '\0';
		stash = string;
		string = ft_strjoin(stash, buff);
		free(stash);
	}
	return (free(buff), string);
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*stash;
	int			rt;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	rt = 1;
	string = read_save_string(fd, string, rt);
	if (!string)
		return (NULL);
	stash = keep_left(string);
	if (!stash)
		return (free(string), string = NULL, NULL);
	string = keep_right(string);
	return (stash);
}
