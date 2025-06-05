/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:54:13 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/04 16:54:40 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate_b(int *pos_b, int *size_b, t_stack **stack_b)
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

void	rotate_a(int *pos_a, int *size_a, t_stack **stack_a)
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

void	execute_cheapest_move(t_stack **a, t_stack **b)
{
	int	value;
	int	pos_a;
	int	pos_b;
	int	size_a;
	int	size_b;

	value = find_cheapest_push_to_a(*a, *b);
	pos_b = get_index(*b, value);
	pos_a = find_position_in_a(*a, value);
	size_b = ft_stack_size(*b);
	size_a = ft_stack_size(*a);
	// Rotate stack B to bring value to top
	if (pos_b <= size_b / 2)
		while (pos_b-- > 0)
		{
			rb(b);
			ft_printf("rb\n");
		}
	else
		while (pos_b++ < size_b)
		{
			rrb(b);
			ft_printf("rrb\n");
		}
	// Rotate stack A to correct insert position
	if (pos_a <= size_a / 2)
		while (pos_a-- > 0)
		{
			ra(a);
			ft_printf("ra\n");
		}
	else
		while (pos_a++ < size_a)
		{
			rra(a);
			ft_printf("rra\n");
		}
	// Push it
	pa(a, b);
	ft_printf("pa\n");
}
