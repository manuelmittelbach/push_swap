/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmittelb <mmittelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:54:08 by mmittelb          #+#    #+#             */
/*   Updated: 2025/08/04 15:02:51 by mmittelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

static void	putposition(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		double_count;

	tmp = *head;
	while (tmp)
	{
		tmp2 = *head;
		double_count = 0;
		while (tmp2)
		{
			if (tmp2 -> content > tmp -> content)
				tmp2 -> position++;
			if (tmp2 -> content == tmp -> content)
				double_count++;
			if (double_count == 2)
			{
				write(2, "Error\n", 6);
				free_nodes(head);
				exit(1);
			}
			tmp2 = tmp2 -> next;
		}
		tmp = tmp -> next;
	}
}

static void	create_stack_a(char **argv, t_list **head_a,\
	t_list **tail_a, int argc)
{
	int		i;
	int		j;
	char	**argument;
	t_list	*node;

	if (argc == 1)
		exit(1);
	j = 1;
	while (argv[j])
	{
		argument = ft_split(head_a, argv[j], ' ');
		i = 0;
		while (argument[i])
		{
			node = create_node(ft_atol(argument[i], head_a, &argument, i));
			lst_add_back(head_a, tail_a, node);
			free(argument[i]);
			i++;
		}
		free(argument);
		j++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*tail_a;

	head_b = NULL;
	head_a = NULL;
	tail_a = NULL;
	is_number_check(argv);
	create_stack_a(argv, &head_a, &tail_a, argc);
	putposition(&head_a);
	use_operations(&head_a, &head_b, &tail_a);
	ko_ok_check(&head_a, &head_b);
	free_nodes(&head_a);
	return (0);
}
