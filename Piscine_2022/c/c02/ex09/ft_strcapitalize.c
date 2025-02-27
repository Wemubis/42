/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 04:18:42 by wemubis_          #+#    #+#             */
/*   Updated: 2022/07/15 03:50:32 by wemubis_         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str);

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	cap;

	i = 0;
	cap = 1;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			if (cap == 1)
				str[i] -= 32;
			cap = 0;
		}
		else if (str[i] >= 48 && str[i] <= 57)
			cap = 0;
		else
			cap = 1;
		i++;
	}
	return (str);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] +32;
		i++;
	}
	return (str);
}
