/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:22:51 by daflynn           #+#    #+#             */
/*   Updated: 2025/03/26 13:22:39 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../libft/libft.h"

void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);

void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

void	ra(t_list **stack);
void	rb(t_list **stack);

void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);

int		ft_strisdigit(char *str);
int		is_sorted(t_list *stack);

void	radix_sort(t_list **stack_a, t_list **stack_b);

void	move_min_to_top(t_list **stack);
void	max_min_hunting_sort(t_list **stack_a, t_list **stack_b);

void	bucket_sort(t_list **a, t_list **b, int size);
void	ft_bubble_sort(int *arr, int size);
int		get_index(int *sorted, int size, int value);
int		find_max_in_bucket(t_list *b, int *sorted, int size, int bucket,
			int bucket_size);
void	push_to_buckets(t_list **a, t_list **b);
void	sort_bucket(t_list **b, t_list **a);
int		find_max_index(t_list *b);
void	hunter_seeker_algorithm(t_list **stack_a, t_list **stack_b);

void	comp_sort(t_list **stack_a, t_list **stack_b);

// void	hunter_seeker_algorithm(t_list **stack_a, t_list **stack_b);
void	print_stack(t_list *stack);
#endif
