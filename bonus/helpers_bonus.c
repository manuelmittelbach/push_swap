/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmittelb <mmittelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:38:18 by mmittelb          #+#    #+#             */
/*   Updated: 2025/08/04 17:15:47 by mmittelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	ft_error_check(t_list **head_a, char ***argv, int i)
{
	write(2, "Error\n", 6);
	free_nodes(head_a);
	while ((*argv)[i])
	{
		free((*argv)[i]);
		i++;
	}
	free(*argv);
	exit(1);
}

long	ft_atol(char *str, t_list **head_a, char ***argv, int count)
{
	int		i;
	long	result;
	int		neg;

	i = 0;
	result = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48) * neg;
		if (result > INT_MAX || result < INT_MIN)
			ft_error_check(head_a, argv, count);
		i++;
	}
	if (str[i] != '\0' || str[i - 1] == '-' || str[i - 1] == '+')
		ft_error_check(head_a, argv, count);
	return (result);
}

void	free_nodes(t_list **head_a)
{
	t_list	*tmp;

	while (*head_a)
	{
		tmp = (*head_a)-> next;
		free(*head_a);
		*head_a = tmp;
	}
}

t_list	*create_node(int content)
{
	t_list	*a;

	a = malloc(sizeof(t_list));
	if (!a)
		return (NULL);
	a -> position = 1;
	a -> content = content;
	a -> next = NULL;
	a -> previous = NULL;
	return (a);
}

void	lst_add_back(t_list **head, t_list **tail, t_list *new_node)
{
	t_list	*tmp;

	tmp = *head;
	if (!head || !new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	while (tmp -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = new_node;
	new_node -> previous = tmp;
	*tail = new_node;
}
