/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmittelb <mmittelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:48:54 by mmittelb          #+#    #+#             */
/*   Updated: 2025/07/25 12:21:26 by mmittelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*start_sub;

	if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(sizeof(char) * 1);
		if (!sub)
			return (NULL);
		*sub = '\0';
		return (sub);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	start_sub = sub;
	while (len--)
	{
		*sub = s[start];
		sub++;
		start++;
	}
	*sub = '\0';
	return (start_sub);
}
