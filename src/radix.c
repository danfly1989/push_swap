/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:56:27 by daflynn           #+#    #+#             */
/*   Updated: 2025/03/25 16:25:22 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pushswap.h"

typedef struct variables
{
	int	size;
	int	max_bits;
	int	i;
	int	j;
	int	value;
	int	shift;

}		t_variable;

// Finds the smallest value in the list
int	get_min_value(t_list *stack)
{
	int	min;

	min = *(int *)(stack->content);
	while (stack)
	{
		if (*(int *)(stack->content) < min)
			min = *(int *)(stack->content);
		stack = stack->next;
	}
	return (min);
}

// Finds the maximum value after shifting
int	get_max_bits(t_list *stack, int shift)
{
	int	max;
	int	bits;

	max = *(int *)(stack->content) - shift;
	while (stack)
	{
		if (*(int *)(stack->content) - shift > max)
			max = *(int *)(stack->content) - shift;
		stack = stack->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	init_variables(t_variable *var, t_list *stack_a)
{
	var->size = ft_lstsize(stack_a);
	var->shift = get_min_value(stack_a);
	var->max_bits = get_max_bits(stack_a, var->shift);
	var->i = 0;
}

void	process_bit_level_inverted(t_list **stack_a, t_list **stack_b,
		t_variable *var)
{
	var->j = 0;
	while (var->j < var->size)
	{
		var->value = *(int *)(*stack_a)->content - var->shift;
		// Start from the most significant bit (MSB)
		if ((var->value >> (var->max_bits - var->i)) & 1)
		{
			ra(stack_a);
			ft_printf("ra\n");
		}
		else
		{
			pb(stack_a, stack_b);
			ft_printf("pb\n");
		}
		var->j++;
	}
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		ft_printf("pa\n");
	}
}

void	process_bit_level(t_list **stack_a, t_list **stack_b, t_variable *var)
{
	var->j = 0;
	while (var->j < var->size)
	{
		var->value = *(int *)(*stack_a)->content - var->shift;
		if ((var->value >> var->i) & 1)
		{
			ra(stack_a);
			ft_printf("ra\n");
		}
		else
		{
			pb(stack_a, stack_b);
			ft_printf("pb\n");
		}
		var->j++;
	}
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		ft_printf("pa\n");
	}
}
/*
void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_variable	var;
	t_variable	var;
	t_variable	var;

	init_variables(&var, *stack_a);
	while (var.i < var.max_bits)
	{
		// if (stack_b == NULL && is_sorted(*stack_a))
		// break ;
		process_bit_level_inverted(stack_a, stack_b, &var);
		var.i++;
	}
}*/
void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_variable var;
	while (var.i < var.max_bits) // Iterate over each bit level
	{
		if (*stack_b == NULL && is_sorted(*stack_a))
			// Check if stack_a is sorted and stack_b is empty
			break ; // If already sorted,
		process_bit_level_inverted(stack_a, stack_b, &var);
		// Process bit level sorting
		var.i++;
		// Move to the next bit
	}
}
