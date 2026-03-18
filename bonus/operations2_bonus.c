/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmittelb <mmittelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:57:24 by mmittelb          #+#    #+#             */
/*   Updated: 2025/07/31 11:54:11 by mmittelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	pa(t_list **head_b, t_list **head_a)
{
	t_list	*tmp;

	tmp = *head_b;
	if (*head_b == NULL)
		return ;
	*head_b = (*head_b)-> next;
	if (*head_b)
		(*head_b)-> previous = NULL;
	if (*head_a)
		(*head_a)-> previous = tmp;
	tmp -> next = *head_a;
	tmp -> previous = NULL;
	*head_a = tmp;
}

void	pb(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	tmp = *head_a;
	if (*head_a == NULL)
		return ;
	*head_a = (*head_a)-> next;
	if (*head_a)
		(*head_a)-> previous = NULL;
	if (*head_b)
		(*head_b)-> previous = tmp;
	tmp -> next = *head_b;
	tmp -> previous = NULL;
	*head_b = tmp;
}

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
}
