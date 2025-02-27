/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:10:22 by wemubis_          #+#    #+#             */
/*   Updated: 2022/07/21 19:45:55 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	comp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (*s2 == '\0');
}

char	*ft_strstr(char *str, char *to_find)
{
	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if ((*str == *to_find) && comp(str, to_find))
			return (str);
		str++;
	}
	return ((void *) 0);
}
