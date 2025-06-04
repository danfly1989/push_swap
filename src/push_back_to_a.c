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

/*In this stage, we push everything from STACK_A to STACK_B. 
With one simple exception. 
Every time before we push a number, we check if it is being pushed to the correct position. 
If it is not, we rotate STACK_A until the correct position comes up.*/
void	execute_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	int	target;
	int	pos_a;
	int	pos_b;
	int	size_a;
	int	size_b;

	if (ft_stack_size(*stack_b) == 0)
		return ;
	target = find_cheapest_push_to_a(*stack_a, *stack_b);
	pos_b = get_index(*stack_b, target);
	pos_a = find_position_in_a(*stack_a, target);
	size_a = ft_stack_size(*stack_a);
	size_b = ft_stack_size(*stack_b);
	rotate_b(&pos_b, &size_b, stack_b);
	rotate_a(&pos_a, &size_a, stack_a);
	pa(stack_a, stack_b);
	ft_printf("pa\n");
}
