/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmittelb <mmittelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:34:51 by mmittelb          #+#    #+#             */
/*   Updated: 2025/07/31 11:54:10 by mmittelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

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
}

void	ss(t_list **head_a, t_list **head_b)
{
	sa(head_a);
	sb(head_b);
}
