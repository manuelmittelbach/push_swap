/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmittelb <mmittelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:33:35 by mmittelb          #+#    #+#             */
/*   Updated: 2025/07/25 11:35:31 by mmittelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ra(t_list **head_a, t_list **tail_a)
{
	t_list	*tmp;

	if (*head_a == NULL || (*head_a)-> next == NULL)
		return ;
	tmp = *head_a;
	*head_a = (*head_a)-> next;
	(*head_a)-> previous = NULL;
	(*tail_a)-> next = tmp;
	tmp -> next = NULL;
	tmp -> previous = *tail_a;
	*tail_a = tmp;
}

void	rb(t_list **head_b, t_list **tail_b)
{
	t_list	*tmp;

	if (*head_b == NULL || (*head_b)-> next == NULL)
		return ;
	tmp = *head_b;
	*head_b = (*head_b)-> next;
	(*head_b)-> previous = NULL;
	(*tail_b)-> next = tmp;
	tmp -> next = NULL;
	tmp -> previous = *tail_b;
	*tail_b = tmp;
}

void	rr(t_list **head_a,
	t_list **tail_a,
	t_list **head_b,
	t_list **tail_b)
{
	ra(head_a, tail_a);
	rb(head_b, tail_b);
	write (1, "rr\n", 3);
}

void	rra(t_list **head_a, t_list **tail_a)
{
	t_list	*temp;

	if (*head_a == NULL || (*head_a)-> next == NULL)
		return ;
	temp = *tail_a;
	*tail_a = (*tail_a)-> previous;
	(*tail_a)-> next = NULL;
	temp -> next = *head_a;
	temp -> previous = NULL;
	(*head_a)-> previous = temp;
	*head_a = temp;
	write (1, "rra\n", 4);
}

void	rrb(t_list **head_b, t_list **tail_b)
{
	t_list	*temp;

	if (*head_b == NULL || (*head_b)-> next == NULL)
		return ;
	temp = *tail_b;
	*tail_b = (*tail_b)-> previous;
	(*tail_b)-> next = NULL;
	temp -> next = *head_b;
	temp -> previous = NULL;
	(*head_b)-> previous = temp;
	*head_b = temp;
	write (1, "rrb\n", 4);
}
