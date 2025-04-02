/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:50:28 by daflynn           #+#    #+#             */
/*   Updated: 2025/03/11 12:40:35 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

t_list	*swap(t_list *stack)
{
	t_list	*second;

	if (!stack || !stack->next)
		return (stack);
	second = stack->next;
	stack->next = second->next;
	second->next = stack;
	return (second);
}

void	sa(t_list **stack)
{
	*stack = swap(*stack);
}

void	sb(t_list **stack)
{
	*stack = swap(*stack);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
