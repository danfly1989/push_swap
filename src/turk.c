/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:18:39 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/03 20:13:57 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

typedef struct s_var
{
	int	target;
	int	rot_a;
	int	rot_b;
	int	size_a;
	int	size_b;

}		t_var;

void	initial_push(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	ft_printf("pb\n");
	pb(stack_a, stack_b);
	ft_printf("pb\n");
}

void	push_until_three(t_stack **a, t_stack **b)
{
	t_var	var;
	int		index;

	while (ft_stack_size(*a) > 3)
	{
		var.size_a = ft_stack_size(*a);
		var.size_b = ft_stack_size(*b);
		var.target = find_cheapest_push_to_b(*a, *b);
		var.rot_a = get_index(*a, var.target);
		var.rot_b = find_insert_position(*b, var.target);
		if (var.rot_a <= var.size_a / 2 && var.rot_b <= var.size_b / 2)
			while (var.rot_a-- > 0 && var.rot_b-- > 0 && ft_printf("rr\n"))
				rr(a, b);
		else if (var.rot_a > var.size_a / 2 && var.rot_b > var.size_b / 2)
			while (var.rot_a++ < var.size_a && var.rot_b++ < var.size_b
				&& ft_printf("rrr\n"))
				rrr(a, b);
		rotate_to_top(a, var.rot_a);
		index = find_insert_position(*b, var.target);
		rotate_target_to_top(var.rot_b, var.size_b, b, index);
		pb(a, b);
		ft_printf("pb\n");
	}
}

void	execute_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	int	target;
	int	rot_b;
	int	size_b;
	int	rot_a;

	target = find_cheapest_push_to_a(*stack_a, *stack_b);
	if (target == -1)
		return ;
	rot_b = get_index(*stack_b, target);
	size_b = ft_stack_size(*stack_b);
	rotate_target_to_top(rot_b, size_b, stack_b, target);
	rot_a = find_insert_position(*stack_a, target);
	rotate_to_top(stack_a, rot_a);
	pa(stack_a, stack_b);
	ft_printf("pa\n");
}

void	final_align(t_stack **stack_a)
{
	int	min_index;
	int	size;

	min_index = find_min_index(*stack_a);
	size = ft_stack_size(*stack_a);
	if (min_index <= size / 2)
		while (min_index-- > 0 && ft_printf("ra\n"))
			ra(stack_a);
	else
		while (min_index++ < size && ft_printf("rra\n"))
			rra(stack_a);
}

/*Flow of mechanical turk:
initial blind bush of 2 to b
find the min number of rotations to push to b an d push above max in b
continue until 3 remain in a
call optimized sort for three
once a is sorted, find the cheapest push back to a in sorted order
rotate the minimum to the first place according to cheapest direction*/
void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	initial_push(stack_a, stack_b);
	push_until_three(stack_a, stack_b);
	sort_three(stack_a);
	if (ft_stack_size(*stack_a) == 2 && !ft_is_sorted(*stack_a)
		&& ft_printf("sa\n"))
		sa(stack_a);
	while (ft_stack_size(*stack_b) > 0)
		execute_cheapest_move(stack_a, stack_b);
	final_align(stack_a);
}
