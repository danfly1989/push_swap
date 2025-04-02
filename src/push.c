/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:55:08 by daflynn           #+#    #+#             */
/*   Updated: 2025/03/11 15:16:21 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	push(t_list **src, t_list **dest)
{
	t_list	*top;

	if (!*src)
		return ;
	top = *src;
	*src = top->next;
	top->next = *dest;
	*dest = top;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
}
