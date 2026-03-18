/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmittelb <mmittelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:46:18 by mmittelb          #+#    #+#             */
/*   Updated: 2025/07/25 11:49:08 by mmittelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	forward_or_back(t_num n, t_list **head, t_list **tale)
{
	if (n.count_forward < n.count_back)
	{
		while (n.count_forward--)
		{
			rb(head, tale);
			write (1, "rb\n", 3);
		}
	}
	else
	{
		while (n.count_back--)
			rrb(head, tale);
	}
}

static void	find_closest_node_in_b(t_list **head_b,
			t_list **head_a, t_list **tale, t_num n)
{
	t_list	*tmp_f;
	t_list	*tmp_b;

	tmp_f = *head_b;
	tmp_b = *tale;
	n.count_forward = 0;
	while (tmp_f && tmp_f->position <\
	(n.count_arguments - (n.chunk_number * n.chunk_size)))
	{
		n.count_forward++;
		tmp_f = tmp_f -> next;
	}
	n.count_back = 1;
	while (tmp_b && tmp_b -> position < \
	(n.count_arguments - (n.chunk_number * n.chunk_size)))
	{
		n.count_back++;
		tmp_b = tmp_b -> previous;
	}
	forward_or_back(n, head_b, tale);
	pa(head_b, head_a);
}

static void	sort_three(t_list **head_a, t_list **head_b)
{
	sa(head_a);
	if ((*head_a)-> position < (*head_a)-> next -> position
		&& (*head_a)-> next -> position < (*head_a)-> next -> next -> position)
		return ;
	pb(head_a, head_b);
	sa(head_a);
	pa(head_b, head_a);
}

void	push_three(t_list **head_b,
			t_list **head_a, t_list **tail_b, t_num n)
{
	find_closest_node_in_b(head_b, head_a, tail_b, n);
	find_closest_node_in_b(head_b, head_a, tail_b, n);
	if ((*head_a)-> position > (*head_a)-> next -> position)
		sa(head_a);
	find_closest_node_in_b(head_b, head_a, tail_b, n);
	if (!((*head_a)-> position < (*head_a)-> next -> position &&\
		(*head_a)-> next -> position <\
		(*head_a)-> next -> next -> position))
		sort_three(head_a, head_b);
}
