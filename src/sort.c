/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmittelb <mmittelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:44:23 by mmittelb          #+#    #+#             */
/*   Updated: 2025/08/04 15:32:30 by mmittelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	find_closest_node_in_a(t_list **head_a,
			t_list **head_b, t_list **tale_a, t_num n)
{
	t_list	*tail_b;

	while (((*head_a)-> position) > (n.chunk_number * n.chunk_size) && *head_a)
	{
		ra(head_a, tale_a);
		write (1, "ra\n", 3);
	}
	pb(head_a, head_b);
	tail_b = *head_b;
	while (tail_b -> next)
		tail_b = tail_b -> next;
	if ((*head_b)-> position <= \
	(n.chunk_number * n.chunk_size) - (n.chunk_size / 2))
	{
		if (*head_a && (*head_a)-> position > (n.chunk_number * n.chunk_size))
			rr(head_a, tale_a, head_b, &tail_b);
		else
		{
			rb(head_b, &tail_b);
			write (1, "rb\n", 3);
		}
	}
}

void	push_all_to_a(t_list **head_a, t_list **head_b, t_num n)
{
	t_list	*tail_b;

	tail_b = *head_b;
	while (tail_b -> next)
		tail_b = tail_b -> next;
	n.chunk_number = 1;
	n.chunk_size = 3;
	while (1)
	{
		if (count_nodes(head_b) < 3)
		{
			while (*head_b)
				pa(head_b, head_a);
			if ((*head_a)-> position > (*head_a)-> next -> position)
				sa(head_a);
			break ;
		}
		push_three(head_b, head_a, &tail_b, n);
		n.chunk_number++;
	}
}

void	sort(t_list **head_a, t_list **tail_a, int argc)
{
	t_list	*head_b;
	int		tmp;
	t_num	n;

	n.count_arguments = argc;
	head_b = NULL;
	n.chunk_number = 1;
	while (1)
	{
		n.chunk_size = define_chunksize(argc);
		tmp = n.chunk_size;
		if (count_nodes(head_a) < n.chunk_size)
		{
			while (*head_a)
				pb(head_a, &head_b);
			break ;
		}
		while (tmp--)
			find_closest_node_in_a(head_a, &head_b, tail_a, n);
		n.chunk_number++;
	}
	push_all_to_a(head_a, &head_b, n);
}
