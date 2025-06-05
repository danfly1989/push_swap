/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>       +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:18:39 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/03 20:13:57 by daflynn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

typedef struct s_vars
{
	int	pos_a;
	int	pos_b;
	int	size_a;
	int	size_b;
	int	cost_a;
	int	cost_b;

}		t_vars;

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
		adjust_stack_b(&pos_b, &size_b, b);
		pb(a, b);
		ft_printf("pb\n");
	}
	sort_three(a);
}

// Calculate total cost to move element from B to A
int	calculate_cost_b_to_a(t_stack *stack_a, t_stack *stack_b, int value)
{
	t_vars	var;

	var.pos_b = get_index(stack_b, value);
	var.pos_a = find_position_in_a(stack_a, value);
	var.size_a = ft_stack_size(stack_a);
	var.size_b = ft_stack_size(stack_b);
	if (var.pos_a <= var.size_a / 2)
		var.cost_a = var.pos_a;
	else
		var.cost_a = var.size_a - var.pos_a;
	if (var.pos_b <= var.size_b / 2)
		var.cost_b = var.pos_b;
	else
		var.cost_b = var.size_b - var.pos_b;
	return (var.cost_a + var.cost_b);
}

int	find_cheapest_push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;
	int		cheapest;
	int		min_cost;
	int		current_cost;

	current = stack_b;
	cheapest = current->num;
	min_cost = calculate_cost_b_to_a(stack_a, stack_b, current->num);
	while (current)
	{
		current_cost = calculate_cost_b_to_a(stack_a, stack_b, current->num);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest = current->num;
		}
		current = current->next;
	}
	return (cheapest);
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
	while (ft_stack_size(*stack_b) > 0)
		execute_cheapest_move(stack_a, stack_b);
	final_align(stack_a);
	ft_printf("FINAL STACK STATE:\n");
	ft_print_stack(*stack_a);
}
