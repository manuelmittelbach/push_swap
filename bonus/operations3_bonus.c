/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmittelb <mmittelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:58:19 by mmittelb          #+#    #+#             */
/*   Updated: 2025/07/31 11:50:03 by mmittelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

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
}

void	rrr(t_list **head_a,
	t_list **tail_a,
	t_list **head_b,
	t_list **tail_b)
{
	rra(head_a, tail_a);
	rrb(head_b, tail_b);
}
