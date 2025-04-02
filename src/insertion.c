/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:11:02 by daflynn           #+#    #+#             */
/*   Updated: 2025/03/12 14:53:44 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "pushswap.h"

void	rotate_and_push(t_list **stack_a, t_list **stack_b, int value)
{
	int	size;
	int	rotations;

	size = ft_lstsize(*stack_b);
	rotations = 0;
	while ((rotations < size) && *stack_b
		&& *(int *)(*stack_b)->content > value)
	{
		rb(stack_b);
		ft_printf("rb\n");
		rotations++;
	}
	pb(stack_a, stack_b);
	ft_printf("pb\n");
	while (rotations-- > 0)
	{
		rrb(stack_b);
		ft_printf("rrb\n");
	}
}

void	insertion_sort(t_list **stack_a, t_list **stack_b)
{
	int	value;

	while (*stack_a)
	{
		value = *(int *)((*stack_a)->content);
		if (!*stack_b || value > *(int *)(*stack_b)->content)
		{
			pb(stack_a, stack_b);
			ft_printf("pb\n");
		}
		else
			rotate_and_push(stack_a, stack_b, value);
	}
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		ft_printf("pa\n");
	}
}
