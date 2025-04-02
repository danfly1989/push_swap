/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:44:17 by daflynn           #+#    #+#             */
/*   Updated: 2025/03/31 13:44:20 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pushswap.h"
#include <stdlib.h>

int	find_min_index(t_list *stack)
{
	int	min;
	int	min_index;
	int	i;

	if (!stack)
		return (-1);
	min = *(int *)(stack->content);
	min_index = 0;
	i = 0;
	while (stack)
	{
		if (*(int *)(stack->content) < min)
		{
			min = *(int *)(stack->content);
			min_index = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_index);
}

void	move_min_to_top(t_list **stack)
{
	int	min_index;
	int	size;
	int	rotations;

	size = ft_lstsize(*stack);
	if (size < 2)
		return ;
	min_index = find_min_index(*stack);
	if (min_index <= size / 2)
	{
		while (min_index-- > 0)
		{
			ra(stack);
			ft_printf("ra\n");
		}
	}
	else
	{
		rotations = size - min_index;
		while (rotations-- > 0)
		{
			rra(stack);
			ft_printf("rra\n");
		}
	}
}

void	move_max_to_top(t_list **stack)
{
	int	max_index;
	int	size;
	int	rotations;

	size = ft_lstsize(*stack);
	if (size < 2)
		return ;
	max_index = find_max_index(*stack);
	if (max_index <= size / 2)
	{
		while (max_index-- > 0)
		{
			ra(stack);
			ft_printf("ra\n");
		}
	}
	else
	{
		rotations = size - max_index;
		while (rotations-- > 0)
		{
			rra(stack);
			ft_printf("rra\n");
		}
	}
}

void	print_stack(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current)
	{
		ft_printf("%d ", *(int *)current->content);
		// Print the integer value at the current node
		current = current->next;
	}
	printf("\n");
}

void	comp_sort(t_list **stack_a, t_list **stack_b)
{
	int			size;
	static int	counter;

	size = ft_lstsize(*stack_a);
	counter = size;
	ft_putendl_fd("======= PASS OPERATIONS =======", 1);
	if ((*stack_a))
	{
		pb(stack_a, stack_b);
		ft_putendl_fd("pb", 1);
	}
	else
	{
		return ;
	}
	ft_putendl_fd("======= STATE AFTER PASS =======", 1);
	ft_printf("A:");
	print_stack(*stack_a);
	ft_printf("B:");
	print_stack(*stack_b);
	ft_putendl_fd("==========END===========", 1);
	ft_putendl_fd("=========================", 1);
	ft_putendl_fd("", 1);
	while (counter)
	{
		counter--;
		comp_sort(stack_a, stack_b);
	}
}
