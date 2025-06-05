/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:22:51 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/02 13:46:06 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

// Simple doubly linked list with a node containing a single number
typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;

}					t_stack;

// Generic stack functions
void				ft_stack_clear(t_stack **stack);
t_stack				*ft_create_node(int num);
t_stack				*ft_fill_stack(char *arg);
void				ft_print_stack(t_stack *stack);

// stack updating functions (update.c)
void				ft_push(t_stack **stack, t_stack *new_node);
void				ft_append_node(t_stack **stack, t_stack *new_node);

// push_swap operations
void				pb(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				swap(t_stack **stack);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rotate(t_stack **stack);
void				reverse(t_stack **stack);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

// sort_three
int					ft_is_hogback(t_stack *stack);
void				sort_three(t_stack **stack);
int					ft_is_reversed(t_stack *stack);
void				single_case(t_stack **stack);

// stack reading functions (read.c)
int					get_index(t_stack *stack, int value);
int					find_min_index(t_stack *stack);
void				push_swap(t_stack **stack_a, t_stack **stack_b);
int					ft_stack_size(t_stack *stack);
int					ft_is_sorted(t_stack *stack);

// turk funcs
int					is_valid_number(char *str);
int					validate_input(int argc, char **argv);
int					find_cheapest_push_to_b(t_stack *stack_a, t_stack *stack_b);

// the turk helpers
int					find_max(t_stack *stack);
int					find_min(t_stack *stack);
int					find_position_in_a(t_stack *stack_a, int value);
void				initial_push(t_stack **stack_a, t_stack **stack_b);

// isolating push_until_three for clarity
int					calculate_cost_a_to_b(t_stack *stack_a, t_stack *stack_b,
						int value);
int					find_position_in_b(t_stack *stack_b, int value);
void				adjust_stack_a(int *pos_a, int *size_a, t_stack **stack_a);
void				adjust_stack_b(int *pos_b, int *size_b, t_stack **stack_b);

// pushing back to a
// void				execute_cheapest_move(t_stack **stack_a, t_stack **stack_b);

#endif
