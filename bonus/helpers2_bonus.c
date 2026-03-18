/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmittelb <mmittelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:51:34 by mmittelb          #+#    #+#             */
/*   Updated: 2025/08/04 15:04:15 by mmittelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	is_number_check(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '+')
				j++;
			else if (argv[i][j] == '-')
				j++;
			else if ((argv[i][j] >= 9 && argv[i][j] <= 13) || argv[i][j] == 32)
				j++;
			else
			{
				write(2, "Error\n", 6);
				exit (1);
			}
		}
		i++;
	}
}

int	count_nodes(t_list **head)
{
	int		count;
	t_list	*tmp;

	tmp = *head;
	count = 0;
	while (tmp)
	{
		tmp = tmp -> next;
		count++;
	}
	return (count);
}

int	ft_strcmp(const char *s1, const char *s2)

{
	size_t				i;
	const unsigned char	*s1u;
	const unsigned char	*s2u;

	s1u = (const unsigned char *)s1;
	s2u = (const unsigned char *)s2;
	i = 0;
	while (s1u[i] != '\0' || s2u[i] != '\0')
	{
		if (s1u[i] == s2u[i])
			i++;
		else if (s1u[i] != s2u[i])
			return (s1u[i] - s2u[i]);
	}
	return (0);
}
