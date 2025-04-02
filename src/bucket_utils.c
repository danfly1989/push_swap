#include "../libft/libft.h"
#include "pushswap.h"

int	get_index(int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	sort_bucket(t_list **b, t_list **a)
{
	int	max_pos;
	int	size_b;

	if (!*b)
		return ;
	while (!is_sorted(*b))
	{
		max_pos = find_max_index(*b);
		size_b = ft_lstsize(*b);
		if (max_pos > size_b / 2)
		{
			while (max_pos++ < size_b)
			{
				rrb(b);
				ft_printf("rrb\n");
			}
		}
		else
		{
			while (max_pos-- > 0)
			{
				rb(b);
				ft_printf("rb\n");
			}
		}
		pa(a, b); // Assuming 'a' is accessible; may need parameter adjustment
		ft_printf("pa\n");
	}
}

int	find_max_index(t_list *b)
{
	int		max_val;
	int		max_idx;
	int		i;
	t_list	*tmp;

	max_val = *(int *)b->content;
	max_idx = 0;
	i = 0;
	tmp = b;
	while (tmp)
	{
		if (*(int *)tmp->content > max_val)
		{
			max_val = *(int *)tmp->content;
			max_idx = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (max_idx);
}

void	ft_bubble_sort(int *arr, int size)
{
	int i;
	int j;
	int temp;
	int swapped;

	i = 0;
	while (i < size - 1)
	{
		swapped = 0;
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
		i++;
	}
}