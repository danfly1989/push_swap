/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:01:16 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/02 12:01:20 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	initial_push(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_size(*stack_a) < 2)
		return ;
	pb(stack_a, stack_b);
	ft_printf("pb\n");
	if (ft_stack_size(*stack_a) > 0)
	{
		pb(stack_a, stack_b);
		ft_printf("pb\n");
	}
}

int	find_max(t_stack *stack)
{
	int		max;
	t_stack	*current;

	if (!stack)
		return (0);
	max = stack->num;
	current = stack;
	while (current)
	{
		if (current->num > max)
			max = current->num;
		current = current->next;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int		min;
	t_stack	*current;

	if (!stack)
		return (0);
	min = stack->num;
	current = stack;
	while (current)
	{
		if (current->num < min)
			min = current->num;
		current = current->next;
	}
	return (min);
}

// Find the best position in stack A to insert element from B
int	find_position_in_a(t_stack *stack_a, int value)
{
	t_stack	*current;
	int		position;
	int		min_a;
	int		max_a;

	if (!stack_a)
		return (0);
	min_a = find_min(stack_a);
	max_a = find_max(stack_a);
	if (value < min_a)
		return (get_index(stack_a, min_a));
	if (value > max_a)
		return (get_index(stack_a, min_a));
	current = stack_a;
	position = 0;
	while (current && current->next)
	{
		if (current->num < value && current->next->num > value)
			return (position + 1);
		current = current->next;
		position++;
	}
	if (stack_a->num > value && current->num < value)
		return (0);
	return (0);
}
