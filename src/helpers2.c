/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmittelb <mmittelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:51:34 by mmittelb          #+#    #+#             */
/*   Updated: 2025/08/04 15:11:04 by mmittelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	define_chunksize(int argc)
{
	if (argc < 102)
		return (20);
	if (argc < 502 && argc > 101)
		return (47);
	return (50);
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

int	sorted(t_list **head_a)
{
	t_list	*tmp;

	tmp = *head_a;
	while (tmp)
	{
		if (tmp -> next && tmp -> content > tmp -> next -> content)
			return (0);
		tmp = tmp-> next;
	}
	return (1);
}

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
