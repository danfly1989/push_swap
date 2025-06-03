/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:20:52 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/03 14:21:05 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*This function frees a string array and is only called by
validate_input and is thus located here*/
static void	free_str_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

/*checks overflow for is_valid_number*/
static int	check_overflow(long num, int sign)
{
	if ((sign == 1 && num > INT_MAX) || (sign == -1 && num > -(long)INT_MIN))
		return (1);
	return (0);
}

int	is_valid_number(char *str)
{
	int		i;
	long	num;
	int		sign;

	if (!str || !*str)
		return (0);
	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	if (!str[i])
		return (0);
	num = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i++] - '0');
		if (check_overflow(num, sign))
			return (0);
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (0);
	return (1);
}

int	validate_input(int argc, char **argv)
{
	int		i;
	int		j;
	char	**nums;

	i = 1;
	while (i < argc)
	{
		nums = ft_split(argv[i], ' ');
		if (!nums || !*nums)
			return (free_str_array(nums), 0);
		j = 0;
		while (nums[j])
		{
			if (!is_valid_number(nums[j]))
				return (free_str_array(nums), 0);
			j++;
		}
		free_str_array(nums);
		i++;
	}
	return (1);
}
