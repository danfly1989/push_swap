/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:41:53 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/02 11:42:00 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pushswap.h"

t_stack	*ft_create_node(int num)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	*ft_fill_stack(char *arg)
{
	t_stack	*stack;
	char	**nums;
	int		i;
	int		n;

	stack = NULL;
	nums = ft_split(arg, ' ');
	i = 0;
	while (nums[i])
	{
		n = ft_atoi(nums[i]);
		ft_append_node(&stack, ft_create_node(n));
		i++;
	}
	i = 0;
	while (nums[i])
		free(nums[i++]);
	free(nums);
	return (stack);
}
