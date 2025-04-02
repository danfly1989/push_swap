/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:00:50 by daflynn           #+#    #+#             */
/*   Updated: 2025/03/12 13:58:13 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

t_list	*reverse_rotate(t_list *stack)
{
	t_list	*second_last;
	t_list	*last;

	if (!stack || !stack->next)
		return (stack);
	second_last = stack;
	while (second_last->next && second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = stack;
	return (last);
}

void	rra(t_list **stack)
{
	*stack = reverse_rotate(*stack);
}

void	rrb(t_list **stack)
{
	*stack = reverse_rotate(*stack);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
