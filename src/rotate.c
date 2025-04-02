/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:59:10 by daflynn           #+#    #+#             */
/*   Updated: 2025/03/11 15:17:09 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

t_list	*rotate(t_list *stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !stack->next)
		return (stack);
	first = stack;
	last = stack;
	while (last->next)
		last = last->next;
	stack = first->next;
	first->next = NULL;
	last->next = first;
	return (stack);
}

void	ra(t_list **stack)
{
	*stack = rotate(*stack);
}

void	rb(t_list **stack)
{
	*stack = rotate(*stack);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
