/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:40:59 by daflynn           #+#    #+#             */
/*   Updated: 2025/03/25 15:09:42 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pushswap.h"

int	ft_strisdigit(char *str)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	i = 0;
	if (len == 0)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i == len)
		return (0);
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
		{
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}

t_list	*duplicate_stack(t_list *stack)
{
	t_list	*new_stack;
	t_list	*new_node;
	int		*value;

	new_stack = NULL;
	while (stack)
	{
		value = malloc(sizeof(int));
		if (!value)
		{
			ft_lstclear(&new_stack, free);
			return (NULL);
		}
		*value = *(int *)stack->content;
		new_node = ft_lstnew(value);
		if (!new_node)
		{
			free(value);
			ft_lstclear(&new_stack, free);
			return (NULL);
		}
		ft_lstadd_back(&new_stack, new_node);
		stack = stack->next;
	}
	return (new_stack);
}
