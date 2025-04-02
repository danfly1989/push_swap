#include "pushswap.h"

int	*copy_and_sort(t_list *a, int size)
{
	int		*sorted;
	t_list	*tmp;
	int		i;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	tmp = a;
	i = 0;
	while (i < size)
	{
		sorted[i] = *(int *)tmp->content;
		tmp = tmp->next;
		i++;
	}
	ft_bubble_sort(sorted, size);
	return (sorted);
}

static void	process_bucket(t_list **a, t_list **b, int *sorted,
		int bucket_info[3])
{
	int	start;
	int	end;
	int	bucket_size;
	int	ra_count;
	int	pb_count;
	int	total;
	int	val;
	int	pos;

	start = bucket_info[0];
	end = bucket_info[1];
	bucket_size = bucket_info[2];
	ra_count = 0;
	pb_count = 0;
	total = ft_lstsize(*a);
	for (int i = 0; i < total; i++)
	{
		val = *(int *)(*a)->content;
		pos = get_index(sorted, total, val);
		if (pos >= start && pos < end)
		{
			pb(a, b);
			pb_count++;
			ft_printf("pb\n");
		}
		else
		{
			ra(a);
			ra_count++;
			ft_printf("ra\n");
		}
	}
	for (int i = 0; i < ra_count; i++)
	{
		rra(a);
		ft_printf("rra\n");
	}
}

void	bucket_sort(t_list **a, t_list **b, int size)
{
	int *sorted = copy_and_sort(*a, size);
	int num_buckets = (size > 50) ? 10 : 5; // Adjust based on size
	int bucket_size = (size + num_buckets - 1) / num_buckets;

	for (int bucket = 0; bucket < num_buckets; bucket++)
	{
		int start = bucket * bucket_size;
		int end = (bucket + 1) * bucket_size;
		int bucket_info[3] = {start, end, bucket_size};
		process_bucket(a, b, sorted, bucket_info);
		sort_bucket(b, a);
		while (*b)
		{
			pa(a, b);
			ft_printf("pa\n");
		}
	}
	free(sorted);
}