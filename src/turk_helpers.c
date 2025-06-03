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

typedef struct s_vars
{
	int	min_cost;
	int	cheapest;
	int	cost;
	int	found;

}		t_vars;

// rotates target to the top of be using the minimum number of rotations
void	rotate_target_to_top(int rot_b, int size_b, t_stack **stack_b,
		int target)
{
	int	limit;

	limit = size_b;
	if (rot_b > size_b / 2)
	{
		while ((*stack_b)->num != target && limit-- > 0)
		{
			rrb(stack_b);
			ft_printf("rrb\n");
		}
	}
	else
	{
		while ((*stack_b)->num != target && limit-- > 0)
		{
			rb(stack_b);
			ft_printf("rb\n");
		}
	}
}

int	calculate_cost(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	cost_a;
	int	cost_b;
	int	size_a;
	int	size_b;

	cost_a = find_insert_position(stack_a, value);
	cost_b = get_index(stack_b, value);
	size_a = ft_stack_size(stack_a);
	size_b = ft_stack_size(stack_b);
	if (cost_a > size_a / 2)
		cost_a = size_a - cost_a;
	if (cost_b > size_b / 2)
		cost_b = size_b - cost_b;
	return (cost_a + cost_b);
}

int	find_cheapest_push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;
	t_vars	var;

	if (!stack_b)
		return (-1);
	current = stack_b;
	var.min_cost = INT_MAX;
	var.cheapest = 0;
	var.found = 0;
	while (current)
	{
		var.cost = calculate_cost(stack_a, stack_b, current->num);
		if (!var.found || var.cost < var.min_cost)
		{
			var.min_cost = var.cost;
			var.cheapest = current->num;
			var.found = 1;
		}
		current = current->next;
	}
	if (!var.found)
		return (-1);
	return (var.cheapest);
}

int	find_cheapest_push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	return (find_cheapest_push_to_a(stack_b, stack_a));
}

void	rotate_to_top(t_stack **stack, int rotations)
{
	int	size;

	size = ft_stack_size(*stack);
	if (rotations <= size / 2)
	{
		while (rotations-- > 0)
		{
			ra(stack);
			ft_printf("ra\n");
		}
	}
	else
	{
		rotations = size - rotations;
		while (rotations-- > 0)
		{
			rra(stack);
			ft_printf("rra\n");
		}
	}
}
