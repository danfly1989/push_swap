/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_until_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:17:38 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/05 17:01:00 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <limits.h>

typedef struct s_vars
{
	int	pos_a;
	int	pos_b;
	int	size_b;
	int	size_a;
	int	cost_a;
	int	cost_b;
	int	total_cost;

}		t_vars;

/*Calculate rotary distance to the top of each stack and add them together*/
int	calculate_cost_a_to_b(t_stack *stack_a, t_stack *stack_b, int value)
{
	t_vars	var;

	var.pos_a = get_index(stack_a, value);
	var.pos_b = find_position_in_b(stack_b, value);
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
	if ((var.pos_a <= var.size_a / 2) == (var.pos_b <= var.size_b / 2))
	{
		var.total_cost = var.cost_a + var.cost_b;
		if (var.cost_a > var.cost_b)
			var.total_cost -= var.cost_b;
		else
			var.total_cost -= var.cost_a;
	}
	else
		var.total_cost = var.cost_a + var.cost_b;
	return (var.total_cost);
}

int	find_cheapest_push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;
	int		cheapest;
	int		min_cost;
	int		current_cost;

	current = stack_a;
	cheapest = current->num;
	min_cost = calculate_cost_a_to_b(stack_a, stack_b, current->num);
	while (current)
	{
		current_cost = calculate_cost_a_to_b(stack_a, stack_b, current->num);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest = current->num;
		}
		current = current->next;
	}
	return (cheapest);
}

/*rotate stack a in the most efficient direction
ra if closer to start (middle inclusive)
rra if closer to end*/
void	adjust_stack_a(int *pos_a, int *size_a, t_stack **stack_a)
{
	if (*pos_a <= *size_a / 2)
	{
		while ((*pos_a)-- > 0)
		{
			ra(stack_a);
			ft_printf("ra\n");
		}
	}
	else
	{
		while ((*pos_a)++ < *size_a)
		{
			rra(stack_a);
			ft_printf("rra\n");
		}
	}
}

int	find_position_in_b(t_stack *b, int value)
{
	t_stack	*curr;
	int		pos;
	int		best_pos;
	int		max;

	curr = b;
	pos = 0;
	best_pos = 0;
	max = find_max(b);
	if (!b)
		return (0);
	if (value > max || value < find_min(b))
		return (get_index(b, max) + 1);
	while (curr->next)
	{
		if (curr->num > value && curr->next->num < value)
			return (pos + 1);
		curr = curr->next;
		pos++;
	}
	if (curr->num > value && b->num < value)
		return (0);
	return (best_pos);
}
