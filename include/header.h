/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmittelb <mmittelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:50:56 by mmittelb          #+#    #+#             */
/*   Updated: 2025/08/04 14:58:11 by mmittelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*previous;
	int				content;
	int				position;
}	t_list;

typedef struct numbers
{
	int		chunk_number;
	int		chunk_size;
	int		count_forward;
	int		count_back;
	int		count_arguments;
}	t_num;

long	ft_atol(char *str, t_list **head_a, char ***argv, int count);
void	lst_add_back(t_list **head, t_list **tail, t_list *new_node);
t_list	*create_node(int content);
void	ss(t_list **head_a, t_list **head_b);
void	sa(t_list **head_a);
void	sb(t_list **head_b);
void	pa(t_list **head_b, t_list **head_a);
void	pb(t_list **head_a, t_list **head_b);
void	ra(t_list **head_a, t_list **tail_a);
void	rb(t_list **head_b, t_list **tail_b);
void	rr(t_list **head_a, t_list **tail_a, t_list **head_b,
			t_list **tail_b);
void	rra(t_list **head_a, t_list **tail_a);
void	rrb(t_list **head_b, t_list **tail_b);
int		count_nodes(t_list **head);
void	push_three(t_list **head_b,
			t_list **head_a, t_list **tail_b, t_num n);
void	sort(t_list **head_a, t_list **tail_a, int argc);
void	free_nodes(t_list **head_a);
int		define_chunksize(int argc);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(t_list **head_a, char *s, char c);
int		sorted(t_list **head_a);
void	tiny_sort(t_list **head_a, t_list **tail_a, int count);
void	is_number_check(char **argv);

#endif