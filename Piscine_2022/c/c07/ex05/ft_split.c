/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:18:58 by wemubis_          #+#    #+#             */
/*   Updated: 2022/07/26 23:11:18 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	set_if_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_w(char *str, char *charset)
{
	int	n_word;
	int	i;
	int	bool;

	i = -1;
	bool = 0;
	n_word = 0;
	while (str[++i])
	{
		if (set_if_sep(str[i], charset) && bool == 1)
		{
			n_word++;
			bool = 0;
		}
		else if (set_if_sep(str[i], charset) == 0)
			bool = 1;
	}
	if (bool == 1)
		n_word++;
	return (n_word);
}

int	write_w(char *str, char *charset)
{
	int		j;
	int		i;
	char	*new_str;

	j = 0;
	i = 0;
	while (str[i])
	{
		j += i;
		if (set_if_sep(str[i], charset) == 0)
			new_str[i] = str[j];
		i++;
	}
	return (new_str);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		sep;
	char	**stack;

	sep = 0;
	i = 0;
	stack = malloc(sizeof(char *) * (count_w(str, charset) + 1));
	if (stack == NULL)
		return (NULL);
	while (str[i])
	{
		
	}
	return (stack);
}
