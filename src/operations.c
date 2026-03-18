/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmittelb <mmittelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:33:49 by mmittelb          #+#    #+#             */
/*   Updated: 2025/07/25 12:20:42 by mmittelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sa(t_list **head_a)
{
	t_list	*tmp;
	t_list	*temp;

	if (*head_a == NULL || (*head_a)-> next == NULL)
		return ;
	temp = (*head_a)-> next -> next;
	tmp = *head_a;
	*head_a = (*head_a)-> next;
	(*head_a)-> next = tmp;
	(*head_a)-> next -> next = temp;
	(*head_a)-> next -> previous = *head_a;
	if (temp)
		temp -> previous = (*head_a)-> next;
	(*head_a)-> previous = NULL;
	write (1, "sa\n", 3);
}

void	sb(t_list **head_b)
{
	t_list	*tmp;
	t_list	*temp;

	if (*head_b == NULL || (*head_b)-> next == NULL)
		return ;
	temp = (*head_b)-> next -> next;
	tmp = *head_b;
	*head_b = (*head_b)-> next;
	(*head_b)-> next = tmp;
	(*head_b)-> next -> next = temp;
	(*head_b)-> next -> previous = *head_b;
	if (temp)
		temp -> previous = (*head_b)-> next;
	(*head_b)-> previous = NULL;
	write (1, "sb\n", 3);
}

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
	write (1, "pa\n", 3);
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
	write (1, "pb\n", 3);
}
