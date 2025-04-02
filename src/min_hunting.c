/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* min_hunting.c                                      :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/03/24 18:13:38 by daflynn           #+#    #+#             */
/* Updated: 2025/03/31 09:31:26 by daflynn          ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pushswap.h"
#include <stdlib.h>

int	compare_ints(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	get_element_at_index(t_list *stack, int index)
{
	int	i;

	i = 0;
	while (stack && i < index)
	{
		stack = stack->next;
		i++;
	}
	if (stack)
	{
		return (*(int *)(stack->content));
	}
	return (0); // Handle out of bounds or empty stack
}

int	get_median_of_stack(t_list *stack)
{
	int		size;
	int		*arr;
	t_list	*current;
	int		median;

	size = ft_lstsize(stack);
	if (size == 0)
		return (0);
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (0);
	current = stack;
	for (int i = 0; i < size; i++)
	{
		arr[i] = *(int *)(current->content);
		current = current->next;
	}
	qsort(arr, size, sizeof(int), compare_ints);
	median = arr[size / 2];
	free(arr);
	return (median);
}

void	sort_recursive(t_list **a, t_list **b, int size)
{
	int	median;
	int	moved_to_b;
	int	processed_count;

	moved_to_b = 0;
	processed_count = 0;
	if (size < 2)
		return ;
	median = get_median_of_stack(*a);
	// Move elements smaller than the median to stack b
	while (processed_count < size && ft_lstsize(*a) > 0)
	{
		if (*(int *)((*a)->content) < median)
		{
			pb(a, b);
			ft_printf("pb\n");
			moved_to_b++;
		}
		else
		{
			ra(a);
			ft_printf("ra\n");
		}
		processed_count++;
	}
	// Recursively sort stack b (smaller elements) and stack a (larger elements)
	sort_recursive(b, a, moved_to_b);        // Sort the smaller elements first
	sort_recursive(a, b, size - moved_to_b); // Sort the larger elements
	// Move elements back from stack b to a
	while (moved_to_b > 0)
	{
		pa(a, b);
		ft_printf("pa\n");
		moved_to_b--;
	}
}

void	hunter_seeker_algorithm(t_list **stack_a, t_list **stack_b)
{
	sort_recursive(stack_a, stack_b, ft_lstsize(*stack_a));
}
/*
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
}*/
void	max_min_hunting_sort(t_list **stack_a, t_list **stack_b)
{
	while (*stack_a)
	{
		move_min_to_top(stack_a);
		pb(stack_a, stack_b);
		ft_printf("pb\n");
	}
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		ft_printf("pa\n");
	}
}

void	ft_lstsplit(t_list *stack, t_list **left, t_list **right)
{
	int mid;
	int i;
	t_list *prev;

	if (!stack || !stack->next)
	{
		*left = stack;
		*right = NULL;
		return ;
	}
	mid = ft_lstsize(stack) / 2;
	*left = stack;
	prev = NULL;
	for (i = 0; i < mid; i++)
	{
		prev = stack;
		stack = stack->next;
	}
	if (prev)
		prev->next = NULL;
	*right = stack;
}