#include "../libft/libft.h"
#include "pushswap.h"

char	**split_input(char *input)
{
	return (ft_split(input, ' ')); // Split by spaces
}

static int	is_duplicate(t_list *stack, int num)
{
	while (stack)
	{
		if (*(int *)stack->content == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	exit_with_error(t_list **stack, int *value)
{
	if (value)
		free(value);
	ft_putendl_fd("Error", 2);
	ft_lstclear(stack, free);
	return (1);
}

static int	fill_stack(t_list **stack_a, int argc, char **argv)
{
	t_list	*new;
	int		*value;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strisdigit(argv[i]))
			return (exit_with_error(stack_a, NULL));
		value = malloc(sizeof(int));
		if (!value)
			return (exit_with_error(stack_a, NULL));
		*value = ft_atoi(argv[i]);
		if (is_duplicate(*stack_a, *value))
			return (exit_with_error(stack_a, value));
		new = ft_lstnew(value);
		if (!new)
			return (exit_with_error(stack_a, value));
		ft_lstadd_back(stack_a, new);
		i++;
	}
	return (0);
}

// Function to manually free the array returned by ft_split
static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;
	int		i;
	int		*value;
	t_list	*new;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	// Case when argc == 2 (single string input)
	if (argc == 2)
	{
		args = split_input(argv[1]); // Split the single string argument
		if (!args)
			return (1);
		// Now populate the stack using the split arguments
		i = 0;
		while (args[i])
		{
			if (!ft_strisdigit(args[i]))
			{
				free_split(args); // Free the split array if invalid
				return (1);
			}
			// Proceed as if they are separate arguments
			value = malloc(sizeof(int));
			if (!value)
			{
				free_split(args); // Free the split array if allocation fails
				return (1);
			}
			*value = ft_atoi(args[i]);
			if (is_duplicate(stack_a, *value))
			{
				free_split(args); // Free the split array if duplicate is found
				return (1);
			}
			new = ft_lstnew(value);
			if (!new)
			{
				free_split(args); // Free the split array if list creation fails
				return (1);
			}
			ft_lstadd_back(&stack_a, new);
			i++;
		}
		free_split(args); // Free the split array after usage
	}
	// Standard processing for argc > 2
	else
	{
		if (fill_stack(&stack_a, argc, argv))
			return (1);
	}
	if (is_sorted(stack_a))
		return (0);
	if (argc < 200)
		comp_sort(&stack_a, &stack_b);
	else
		comp_sort(&stack_a, &stack_b);
	// print_stack(stack_a);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
