/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:45:00 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/03 17:28:25 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*Joins all arguments (excluding filename obviously)
together as a single string so that stack
can be filled without any type clashes */
char	*ft_join_args(int argc, char **argv)
{
	char	*joined;
	int		i;
	char	*temp;

	joined = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		temp = ft_strjoin(joined, argv[i]);
		free(joined);
		joined = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	return (joined);
}

/*Brute force alg to check for duplicates
by comparing each number in the stack to every
node that follows it */
int	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next_node;

	current = stack;
	while (current)
	{
		next_node = current->next;
		while (next_node)
		{
			if (current->num == next_node->num)
				return (1);
			next_node = next_node->next;
		}
		current = current->next;
	}
	return (0);
}

/*If single argument is given, fills stack with exactly that string
If multiple arguments given, they will be combined to harmonize
Fails on empty stack or occurrence of duplicates*/
int	process_input(int argc, char **argv, t_stack **stack_a)
{
	char	*joined;

	if (argc == 2)
		*stack_a = ft_fill_stack(argv[1]);
	else
	{
		joined = ft_join_args(argc, argv);
		*stack_a = ft_fill_stack(joined);
		free(joined);
	}
	if (!*stack_a || has_duplicates(*stack_a))
		return (0);
	return (1);
}

/*An unsorted list of two only requires sa 100% of the time*/
void	handle_two_nodes(t_stack **stack_a)
{
	if (!ft_is_sorted(*stack_a))
	{
		ft_printf("sa\n");
		sa(stack_a);
	}
}

/*
 *Main flow of program:
 Exit program if only one argument given (empty line)
 check input and attempt to process into single string
 Print Error if either responsible function fails at this point
 Handle special cases for initial stack of three or less
 In ALL other cases, run the main push_swap algorithm
 * */
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!validate_input(argc, argv) || !process_input(argc, argv, &stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		ft_stack_clear(&stack_a);
		return (1);
	}
	if (ft_is_sorted(stack_a))
		ft_stack_clear(&stack_a);
	else if (ft_stack_size(stack_a) == 2)
		handle_two_nodes(&stack_a);
	else if (ft_stack_size(stack_a) == 3)
		sort_three(&stack_a);
	else
		push_swap(&stack_a, &stack_b);
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
	return (0);
}
