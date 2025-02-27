/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:54:37 by wemubis_          #+#    #+#             */
/*   Updated: 2022/07/22 17:17:19 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

# define ABS(Value) absolute(Value)

int	absolute(int Value)
{
	if (Value < 0)
		Value *= -1;
	return (Value);
}

#endif