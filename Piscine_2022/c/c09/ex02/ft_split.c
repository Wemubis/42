/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:27:29 by wemubis_          #+#    #+#             */
/*   Updated: 2022/07/28 12:49:31 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_norm
{
	int	i;
	int	cnt;
	int	word;
	int	i2;
	int	len;
}	t_norm;

int	ft_cc(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_w(char *str, char *charset)
{
	int	i;
	int	cnt;
	int	word;

	i = -1;
	cnt = 0;
	word = 0;
	while (str[++i] != '\0')
	{
		if (ft_cc(str[i], charset) == 1 && word == 1)
		{
			cnt++;
			word = 0;
		}
		else if (ft_cc(str[i], charset) == 0)
			word = 1;
	}
	if (word == 1)
		cnt++;
	return (cnt);
}

int	ft_c_len(char *str, char *charset, int index, int i2)
{
	t_norm	z;

	z.cnt = 0;
	z.word = 0;
	z.len = 0;
	while (str[++i2] != '\0')
	{
		if (ft_cc(str[i2], charset) == 1 && z.word == 1)
			z.word = 0;
		else if (ft_cc(str[i2], charset) == 0)
		{
			z.word = 1;
			while ((ft_cc(str[++i2], charset) != 1) && ++z.len != -100000)
			{
				if (ft_cc(str[i2], charset) == 1)
				{
					if (z.cnt == index)
						return (z.len);
					z.len = 0;
					z.cnt++;
				}
			}
		}
	}
	return (z.len);
}

char	*ft_wcpy(char *str, char *charset, int index, char *dest)
{
	t_norm	z;

	z.i = -1;
	z.cnt = 0;
	z.word = 0;
	z.i2 = -1;
	while (str[++z.i] != '\0')
	{
		if (ft_cc(str[z.i], charset) == 1 && z.word == 1)
			z.word = 0;
		else if (ft_cc(str[z.i], charset) == 0)
		{
			z.word = 1;
			while ((ft_cc(str[z.i], charset) != 1))
			{
				if (index == z.cnt)
				dest[++z.i2] = str[z.i];
				z.i++;
				if (ft_cc(str[z.i], charset) == 1)
					z.cnt++;
			}
		}
	}
	dest[z.i2 + 1] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		i2;
	char	**dest;

	i2 = 0;
	if (ft_count_w(str, charset) == 0 || charset[i2] == '\0')
		return (NULL);
	i = ft_count_w(str, charset);
	dest = (char **)malloc(sizeof(char *) * (i + 1));
	if (dest == NULL)
		return (NULL);
	while (i2 < i)
	{
		dest[i2] = (char *)malloc(sizeof(char)
				* ft_c_len(str, charset, i2, -1) + 1);
		if (dest[i2] == NULL)
			return (NULL);
		dest[i2] = ft_wcpy(str, charset, i2, dest[i2]);
		i2++;
	}
	dest[i] = NULL;
	return (dest);
}
