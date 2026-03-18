/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmittelb <mmittelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:31:19 by mmittelb          #+#    #+#             */
/*   Updated: 2025/08/04 14:54:29 by mmittelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

static int	ft_wordlen(char const *s, int i, char c)
{
	int	count;

	count = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		count = count + 1;
	}
	return (count);
}

static int	ft_stramount(char const *s, char c)
{
	int		count;
	size_t	i;
	size_t	b_index;

	count = 0;
	b_index = ft_strlen(s) - 1;
	while (s[b_index] == c)
		b_index--;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] && i <= b_index)
	{
		while (s[i] && s[i] != c)
			s++;
		count++;
		while (s[i] == c)
			s++;
	}
	return (count);
}

static char	**ft_free(char **ptr, int j)
{
	while (j >= 0)
	{
		free(ptr[j]);
		j--;
	}
	free(ptr);
	return (NULL);
}

static void	ft_edge(char **s, t_list **head_a)
{
	int	i;

	i = 0;
	while (((*s)[i] >= 9 && (*s)[i] <= 13) || (*s)[i] == 32)
		i++;
	if ((*s)[i] == '\0')
	{
		write(2, "Error\n", 6);
		free_nodes(head_a);
		exit (1);
	}
}

char	**ft_split(t_list **head_a, char *s, char c)
{
	int		i;
	int		j;
	char	**ptr;

	i = 0;
	j = 0;
	ft_edge(&s, head_a);
	ptr = malloc(sizeof(char *) * (ft_stramount(s, c) + 1));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == '\0')
			break ;
		ptr[j] = ft_substr(s, i, ft_wordlen(s, i, c));
		if (!ptr[j])
			return (ft_free(ptr, j));
		while (s[i] != c && s[i])
			i++;
		j++;
	}
	ptr[j] = NULL;
	return (ptr);
}
