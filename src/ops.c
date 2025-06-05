/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:29:05 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/05 19:29:50 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*moves head of stack a to head of stack b
essentially isolates the node by making the
former head of stack b its next and delinks
by assigning null to the prev pointer*/
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	if (!*stack_a)
		return ;
	node = *stack_a;
	*stack_a = node->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	node->next = *stack_b;
	node->prev = NULL;
	if (*stack_b)
		(*stack_b)->prev = node;
	*stack_b = node;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	if (!*stack_b)
		return ;
	node = *stack_b;
	*stack_b = node->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	node->next = *stack_a;
	node->prev = NULL;
	if (*stack_a)
		(*stack_a)->prev = node;
	*stack_a = node;
}

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
}
