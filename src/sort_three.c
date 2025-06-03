/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:07:43 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/02 11:43:52 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*function to ascertain the specific shape known as hogback
also known as fuji for emulating this shape
						_____________
						/		(3)		\
					/						\___(2)_______
				/											\
_____(1)____/												\____
*/
int	ft_is_hogback(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	if (!stack || !stack->next || !stack->next->next)
		return (0);
	a = stack->num;
	b = stack->next->num;
	c = stack->next->next->num;
	if (b > c && b > a && a < c)
		return (1);
	else
		return (0);
}

/*This function checks if already sorted and cycles
through the two cases requiring two operations
,i.e. when reversed or when in hogback/fuji form (1 3 2)
If none of these trigger, it will call the single case function*/
void	sort_three(t_stack **stack)
{
	if (ft_is_sorted(*stack))
		return ;
	if (ft_is_reversed(*stack))
	{
		ra(stack);
		sa(stack);
		ft_printf("ra\nsa\n");
	}
	else if (ft_is_hogback(*stack))
	{
		rra(stack);
		sa(stack);
		ft_printf("rra\nsa\n");
	}
	else
	{
		single_case(stack);
	}
}

/*This function covers all three cases where only one operation is necessary
e.g. 3 1 2 requires only ra, 2 1 3 requires only sa and 2 3 1 requires only rra

*/
void	single_case(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->num;
	second = (*stack)->next->num;
	third = (*stack)->next->next->num;
	if (second > first && second > third)
	{
		rra(stack);
		ft_printf("rra\n");
	}
	else if (third > second && third > first)
	{
		sa(stack);
		ft_printf("sa\n");
	}
	else
	{
		ra(stack);
		ft_printf("ra\n");
	}
}
