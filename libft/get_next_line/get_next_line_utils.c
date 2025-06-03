/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:19:56 by daflynn           #+#    #+#             */
/*   Updated: 2025/02/27 13:19:21 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	ch = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
		{
			return ((char *)(&s[i]));
		}
		i++;
	}
	if (ch == '\0')
		return ((char *)(&s[i]));
	return (NULL);
}
