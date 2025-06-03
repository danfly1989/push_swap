/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:19:48 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/03 11:20:05 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
 * init_min_max: Finds min/max values and their positions in stack
 * min_max array format:
 * [0] = min_val, [1] = max_val, [2] = min_pos, [3] = max_pos
 * size parameter returns the list length
 */
static void	init_min_max(t_stack *stack, int min_max[4], int *size)
{
	t_stack	*current;

	min_max[0] = stack->num;
	min_max[1] = stack->num;
	min_max[2] = 0;
	min_max[3] = 0;
	*size = 0;
	current = stack;
	while (current)
	{
		if (current->num < min_max[0])
		{
			min_max[0] = current->num;
			min_max[2] = *size;
		}
		if (current->num > min_max[1])
		{
			min_max[1] = current->num;
			min_max[3] = *size;
		}
		current = current->next;
		(*size)++;
	}
}

/*
 * insert_outside_bounds: Handles case when value is smaller than min
 * or larger than max in the stack. Returns position after max value,
 * wrapping around using modulo for circular list behavior.
 */
static int	insert_outside_bounds(int max_pos, int size)
{
	return ((max_pos + 1) % size);
}

/*
 * find_position: Locates insertion point for value within stack's min-max range
 * Returns the position where value should be inserted to maintain sorted order
 * Uses modulo to handle circular list wrapping
 */
static int	find_position(t_stack *stack, int value, int size)
{
	t_stack	*current;
	int		index;

	index = 0;
	current = stack;
	while (current)
	{
		if (current->next && current->num < value && value < current->next->num)
			return ((index + 1) % size);
		else if (!current->next && current->num < value && value < stack->num)
			return ((index + 1) % size);
		current = current->next;
		index++;
	}
	return (0);
}

/*
 * find_insert_position: Main function to determine where to insert a value
 * in a circular sorted stack. Handles three cases:
 * 1. Empty stack (returns 0)
 * 2. Value outside current min/max (insert after max)
 * 3. Value within range (find correct sorted position)
 */
int	find_insert_position(t_stack *stack, int value)
{
	int	min_max[4];
	int	size;

	if (!stack)
		return (0);
	init_min_max(stack, min_max, &size);
	if (value < min_max[0] || value > min_max[1])
		return (insert_outside_bounds(min_max[3], size));
	return (find_position(stack, value, size));
}
