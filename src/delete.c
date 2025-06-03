/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:06:59 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/02 11:07:01 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_pop(t_stack **stack)
{
	t_stack	*temp;

	if (stack == NULL || *stack == NULL)
		return (NULL);
	temp = *stack;
	*stack = temp->next;
	if (*stack)
		(*stack)->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}

void	ft_stack_clear(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
