/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:07:20 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/02 21:47:53 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
void	ft_print_stack(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
	{
		ft_printf("Stack is empty\n");
		return ;
	}
	current = stack;
	while (current)
	{
		ft_printf("%d ", current->num);
		current = current->next;
	}
	ft_printf("\n");
}*/
int	ft_stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	ft_is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_is_reversed(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->num < stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_index(t_stack *head, int value)
{
	t_stack	*current;
	int		index;

	current = head;
	index = 0;
	while (current)
	{
		if (current->num == value)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}

int	find_min_index(t_stack *stack)
{
	t_stack	*current;
	int		min;
	int		index;
	int		min_index;

	if (!stack)
		return (-1);
	current = stack;
	min = current->num;
	index = 0;
	min_index = 0;
	while (current)
	{
		if (current->num < min)
		{
			min = current->num;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	return (min_index);
}
