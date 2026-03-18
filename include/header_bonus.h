/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmittelb <mmittelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:50:56 by mmittelb          #+#    #+#             */
/*   Updated: 2025/08/04 14:57:02 by mmittelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BONUS_H
# define HEADER_BONUS_H

# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

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
void	rrr(t_list **head_a, t_list **tail_a, t_list **head_b, t_list **tail_b);
int		count_nodes(t_list **head);
void	push_all_to_a(t_list **head_a, t_list **head_b, t_num n);
void	sort_three(t_list **head_a, t_list **head_b);
void	sort(t_list **head_a, t_list **tail_a, int argc);
void	find_closest_node_in_a(t_list **head_a,
			t_list **head_b, t_list **tale_a, t_num n);
void	find_closest_node_in_b(t_list **head_b,
			t_list **head_a, t_list **tale, t_num n);
void	forward_or_back(t_num n, t_list **head, t_list **tale);
void	free_nodes(t_list **head_a);
void	push_three(t_list **head_b,
			t_list **head_a, t_list **tail_b, t_num n);
size_t	ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_split(t_list **head_a, char *s, char c);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
int		ft_strcmp(const char *s1, const char *s2);
void	use_operations(t_list **head_a, t_list **head_b, t_list **tail_a);
void	ko_ok_check(t_list **head_a, t_list **head_b);
void	is_number_check(char **argv);

#endif