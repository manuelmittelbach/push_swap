/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmittelb <mmittelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:16:11 by mmittelb          #+#    #+#             */
/*   Updated: 2025/07/29 18:23:48 by mmittelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	sort_3(t_list **head_a, t_list **tail_a)
{
	if (sorted(head_a) == 1)
		return ;
	if ((*head_a)-> content > (*head_a)-> next -> content)
	{
		if ((*head_a)-> content > (*tail_a)-> content)
		{
			ra(head_a, tail_a);
			write(1, "ra\n", 3);
		}
		else
			sa(head_a);
		if (((*head_a)-> content > (*head_a)-> next -> content)
			&& sorted(head_a) != 1)
			sa(head_a);
	}
	else if ((*head_a)-> content < (*head_a)-> next -> content)
	{
		rra(head_a, tail_a);
		if ((*head_a)-> content > (*head_a)-> next -> content)
			sa(head_a);
	}
}

static void	sort_4(t_list **head_a, t_list **tail_a, t_list **head_b)
{
	if ((*head_a)-> next -> position == 1)
	{
		ra(head_a, tail_a);
		write(1, "ra\n", 3);
	}
	else if ((*tail_a)-> position == 1)
		rra(head_a, tail_a);
	else if ((*tail_a)-> previous -> position == 1)
	{
		ra(head_a, tail_a);
		ra(head_a, tail_a);
		write(1, "ra\n", 3);
		write(1, "ra\n", 3);
	}
	pb(head_a, head_b);
	sort_3(head_a, tail_a);
}

static void	re_indexing(t_list **head_a)
{
	t_list	*tmp;

	tmp = *head_a;
	while ((*head_a))
	{
		if ((*head_a)-> position == 2)
			(*head_a)-> position = 1;
		*head_a = (*head_a)-> next;
	}
	*head_a = tmp;
}

static void	sort_5(t_list **head_a, t_list **tail_a, t_list **head_b)
{
	if ((*head_a)-> position == 1 || (*head_a)-> position == 2)
		pb(head_a, head_b);
	else if ((*head_a)-> next -> position == 1
		|| (*head_a)-> next -> position == 2)
	{
		ra(head_a, tail_a);
		write(1, "ra\n", 3);
		pb(head_a, head_b);
	}
	else if ((*tail_a)-> position == 1 || (*tail_a)-> position == 2)
	{
		rra(head_a, tail_a);
		pb(head_a, head_b);
	}
	else if ((*head_a)-> next -> next -> position == 1
		|| (*head_a)-> next -> next -> position == 2)
	{
		ra(head_a, tail_a);
		ra(head_a, tail_a);
		write(1, "ra\n", 3);
		write(1, "ra\n", 3);
		pb(head_a, head_b);
	}
	re_indexing(head_a);
	sort_4(head_a, tail_a, head_b);
}

void	tiny_sort(t_list **head_a, t_list **tail_a, int count)
{
	t_list	*head_b;

	head_b = NULL;
	if (count == 2)
		sa(head_a);
	else if (count == 3)
		sort_3(head_a, tail_a);
	else if (count == 4)
	{
		sort_4(head_a, tail_a, &head_b);
		pa(&head_b, head_a);
	}
	else
	{
		sort_5(head_a, tail_a, &head_b);
		if (head_b -> content < head_b -> next -> content)
			sb(&head_b);
		pa(&head_b, head_a);
		pa(&head_b, head_a);
	}
}
