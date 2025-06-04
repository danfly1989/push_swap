/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_until_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:17:38 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/04 16:12:17 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Finds the best index in stack B
// where a given value from A should be inserted.
//
// Case 1: Value is new max or min
// → Put it just above the current max (after rotating)
//
// Case 2: Value fits between two existing numbers
// → Find the exact spot where it goes between two neighbors
//
// This preserves the descending order of stack B,
// so we don’t have to sort B at any point.
//
#include "pushswap.h"

/*struct for managing the number of variablae declarations
int calculate_cost_a_to_b*/
typedef struct s_vars
{
	int	pos_a;
	int	pos_b;
	int	size_b;
	int	size_a;

}		t_vars;

// Calculates how many operations it would take to:
// - Bring a number from stack A to the top
// - And then place it in the correct position in stack B
//
// Why do we do this?
// Because we want to find the "cheapest" number to push from A to B —
// meaning, the one that requires the fewest total rotations.
//
// We compute:
// - Cost to bring the number to the top of A
// - Cost to rotate B so that the number lands in the right spot
// - We assume rotating both stacks in parallel can help (later optimization)
int	calculate_cost_a_to_b(t_stack *stack_a, t_stack *stack_b, int value)
{
	t_vars	var;
	int		cost_a;
	int		cost_b;

	var.pos_a = get_index(stack_a, value);
	var.pos_b = find_position_in_b(stack_b, value);
	var.size_a = ft_stack_size(stack_a);
	var.size_b = ft_stack_size(stack_b);
	if (var.pos_a <= var.size_a / 2)
		cost_a = var.pos_a;
	else
		cost_a = var.size_a - var.pos_a;
	if (var.pos_b <= var.size_b / 2)
		cost_b = var.pos_b;
	else
		cost_b = var.size_b / 2;
	return (cost_a + cost_b);
}

// This scans every number in stack A and uses `calculate_cost_a_to_b`
// to find out which one is the cheapest to push to stack B.
//
// It returns the value (not index) of the best candidate.
//
// This reflects the blog’s logic: we go through the entire stack,
// do the math, and pick the one that takes the fewest steps.
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

// This is the main loop for the first phase of the sorting algorithm.
//
// What are we doing here?
// - We push everything from A to B *except for 3 elements*
// - We always choose the number that’s cheapest to move,
// so we waste fewer operations
//
// Why leave 3 elements in A?
// Because sorting 3 numbers can always be done in 1 or 2 steps,
// so it’s a good cutoff point.
//
// For each number:
// 1. We find the cheapest number to push from A to B
// 2. We rotate A to bring that number to the top
// 3. We rotate B to the correct spot for inserting that number
// 4. We push it (pb)
//
// Note:
//
//- If the number going into B is the new max or min,
// it goes *after* the current max
// - This keeps B in descending order,
// which makes the final reassembly easier

void	adjust_stack_a(int *pos_a, int *size_a, t_stack **stack_a)
{
	if (*pos_a <= *size_a / 2)
	{
		while (*pos_a-- > 0)
		{
			ra(stack_a);
			ft_printf("ra\n");
		}
	}
	else
	{
		while (*pos_a++ < *size_a)
		{
			rra(stack_a);
			ft_printf("rra\n");
		}
	}
}

void	adjust_stack_b(int *pos_b, int *size_b, t_stack **stack_b)
{
	if (*size_b > 0)
	{
		if (*pos_b <= *size_b / 2)
		{
			while (*pos_b-- > 0)
			{
				rb(stack_b);
				ft_printf("rb\n");
			}
		}
		else
		{
			while (*pos_b++ < *size_b)
			{
				rrb(stack_b);
				ft_printf("rrb\n");
			}
		}
	}
}

// Finds the best index in stack B
// where a given value from A should be inserted.
//
// Case 1: Value is new max or min
// → Put it just above the current max (after rotating)
//
// Case 2: Value fits between two existing numbers
// → Find the exact spot where it goes between two neighbors
//
// This preserves the descending order of stack B,
// so we don’t have to sort B at any point.

int	find_position_in_b(t_stack *stack_b, int value)
{
	t_stack	*current;
	int		position;
	int		best_pos;
	int		max_b;

	if (!stack_b)
		return (0);
	max_b = find_max(stack_b);
	if (value > max_b)
		return (get_index(stack_b, max_b));
	current = stack_b;
	position = 0;
	best_pos = 0;
	while (current && current->next)
	{
		if (current->num > value && current->next->num < value)
			return (position + 1);
		current = current->next;
		position++;
	}
	if (stack_b->num < value && current->num > value)
		return (0);
	return (best_pos);
}
