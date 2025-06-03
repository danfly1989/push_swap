/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:07:50 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/02 11:07:52 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pushswap.h"

void	ft_append_node(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
	new_node->next = NULL;
}

void	ft_prepend_node(t_stack **stack, t_stack *new_node)
{
	if (!new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else
	{
		new_node->next = *stack;
		new_node->prev = NULL;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

void	ft_push(t_stack **stack, t_stack *new_node)
{
	if (!new_node)
		return ;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
