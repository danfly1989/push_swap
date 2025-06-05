/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>       +#+  +:+	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:18:39 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/03 20:13:57 by daflynn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_until_three(t_stack **a, t_stack **b)
{
	int	value;
	int	pos_a;
	int	pos_b;
	int	size_a;
	int	size_b;

	while (ft_stack_size(*a) > 3)
	{
		value = find_cheapest_push_to_b(*a, *b);
		pos_a = get_index(*a, value);
		pos_b = find_position_in_b(*b, value);
		size_a = ft_stack_size(*a);
		size_b = ft_stack_size(*b);
		adjust_stack_a(&pos_a, &size_a, a);
		pb(a, b);
		ft_printf("pb\n");
	}
	sort_three(a);
}

// Rotate stack A to bring the target position to the top,
// choosing the shortest direction.
static void	rotate_a_to_position(t_stack **stack_a, int target_position)
{
	int	size_a;

	size_a = ft_stack_size(*stack_a);
	if (target_position <= size_a / 2)
	{
		while (target_position > 0)
		{
			ra(stack_a);
			ft_printf("ra\n");
			target_position--;
		}
	}
	else
	{
		while (target_position < size_a)
		{
			rra(stack_a);
			ft_printf("rra\n");
			target_position++;
		}
	}
}

// Get the top value from stack B (no cost calculation needed)
// Find where this value should go in stack A
// Rotate stack A until the correct position is at the top
// Choose the shorter rotation direction and push to A when it fits
void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	target_value;
	int	target_position;

	while (ft_stack_size(*stack_b) > 0)
	{
		target_value = (*stack_b)->num;
		target_position = find_position_in_a(*stack_a, target_value);
		rotate_a_to_position(stack_a, target_position);
		pa(stack_a, stack_b);
		ft_printf("pa\n");
	}
}

void	final_align(t_stack **stack_a)
{
	int	min_val;
	int	min_pos;
	int	size;

	if (ft_stack_size(*stack_a) <= 1)
		return ;
	min_val = find_min(*stack_a);
	min_pos = get_index(*stack_a, min_val);
	size = ft_stack_size(*stack_a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
		{
			ra(stack_a);
			ft_printf("ra\n");
		}
	}
	else
	{
		while (min_pos++ < size)
		{
			rra(stack_a);
			ft_printf("rra\n");
		}
	}
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a || ft_stack_size(*stack_a) <= 1)
		return ;
	if (ft_is_sorted(*stack_a))
		return ;
	if (ft_stack_size(*stack_a) == 2)
	{
		if (!ft_is_sorted(*stack_a))
		{
			sa(stack_a);
			ft_printf("sa\n");
		}
		return ;
	}
	if (ft_stack_size(*stack_a) == 3)
	{
		sort_three(stack_a);
		return ;
	}
	initial_push(stack_a, stack_b);
	push_until_three(stack_a, stack_b);
	sort_three(stack_a);
	push_back_to_a(stack_a, stack_b);
	final_align(stack_a);
}
