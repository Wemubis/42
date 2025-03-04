/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wemubis_ <wemubis_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:25:03 by wemubis_          #+#    #+#             */
/*   Updated: 2023/03/17 14:33:31 by wemubis_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_element(int data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		error();
	new->data = data;
	new->prev = new;
	new->next = new;
	return (new);
}

void	push_before(t_stack *stack, t_stack *to_add)
{
	if (!stack || !to_add)
		return ;
	to_add->prev = stack->prev;
	to_add->next = stack;
	to_add->prev->next = to_add;
	to_add->next->prev = to_add;
}

t_stack	*pop(t_pile *stack)
{
	t_stack	*tmp;

	tmp = stack->head;
	if (stack->size == 1)
		stack->head = NULL;
	else
	{
		stack->head = stack->head->next;
		stack->head->prev = stack->head->prev->prev;
		stack->head->prev->next = stack->head;
	}
	tmp->next = tmp;
	tmp->prev = tmp;
	return (tmp);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = stack->next;
	while (current != stack)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(stack);
	stack = NULL;
}
