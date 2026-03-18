/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmittelb <mmittelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:58:47 by mmittelb          #+#    #+#             */
/*   Updated: 2025/08/01 13:08:41 by mmittelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

static void	wrong_command(t_list **head_a, t_list **head_b, char **line)
{
	write(2, "Error\n", 6);
	free_nodes(head_b);
	free_nodes(head_a);
	free(*line);
	exit (1);
}

void	use_operations(t_list **head_a, t_list **head_b, t_list **tail_a)
{
	char	*line;
	t_list	*tail_b;

	line = get_next_line(0);
	while (line != NULL)
	{
		tail_b = *head_b;
		while (*head_b && tail_b -> next)
			tail_b = tail_b -> next;
		if (ft_strcmp(line, "rb\n") == 0)
			rb(head_b, &tail_b);
		else if (ft_strcmp(line, "rr\n") == 0)
			rr(head_a, tail_a, head_b, &tail_b);
		else if (ft_strcmp(line, "rra\n") == 0)
			rra(head_a, tail_a);
		else if (ft_strcmp(line, "rrb\n") == 0)
			rrb(head_b, &tail_b);
		else if (ft_strcmp(line, "rrr\n") == 0)
			rrr(head_a, tail_a, head_b, &tail_b);
		else if (ft_strcmp(line, "ra\n") == 0)
			ra(head_a, tail_a);
		else if (ft_strcmp(line, "sa\n") == 0)
			sa(head_a);
		else if (ft_strcmp(line, "sb\n") == 0)
			sb(head_b);
		else if (ft_strcmp(line, "ss\n") == 0)
			ss(head_a, head_b);
		else if (ft_strcmp(line, "pa\n") == 0)
			pa(head_b, head_a);
		else if (ft_strcmp(line, "pb\n") == 0)
			pb(head_a, head_b);
		else
			wrong_command(head_a, head_b, &line);
		free(line);
		line = get_next_line(0);
	}
}

void	ko_ok_check(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	tmp = *head_a;
	while (tmp && (tmp)-> next)
	{
		if ((tmp)-> content > (tmp)-> next -> content)
		{
			write (1, "KO", 2);
			free_nodes(head_a);
			free_nodes(head_b);
			exit (1);
		}
		tmp = (tmp)-> next;
	}
	if (*head_b != NULL)
	{
		free_nodes(head_b);
		write (1, "KO", 2);
		free_nodes(head_a);
		exit (1);
	}
	write (1, "OK", 2);
}
