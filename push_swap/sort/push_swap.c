/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:33:48 by wemubis_          #+#    #+#             */
/*   Updated: 2023/02/06 20:05:54 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_pile *a, t_pile *b)
{
	if (check_if_sorted(a) == 1)
		return ;
	if (a->size <= 5)
		sort_small(a, b);
	else if (a->size < 10)
		sort_inf_ten(a, b);
	else
		sort_big(a, b);
}
