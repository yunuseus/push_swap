/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:20:30 by yalp              #+#    #+#             */
/*   Updated: 2025/02/13 14:52:52 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_nodes
{
	int				content;
	int				index;
	struct s_nodes	*next;
}	t_nodes;

int			ft_atoi(const char *str);
void		ra(t_nodes **a);
void		sa(t_nodes **a);
void		rr(t_nodes **a, t_nodes **b);
void		rra(t_nodes **a);
t_nodes		*ft_lstlast(t_nodes *lst);
void		ft_lstadd_back(t_nodes **lst, t_nodes *new);
t_nodes		*ft_lstnew(int content);
void		ft_lstadd_front(t_nodes **lst, t_nodes *new);
void		ft_lst_free(t_nodes *list);
int			ft_lstsize(t_nodes *lst);
void		pb(t_nodes **a, t_nodes **b);
void		pa(t_nodes **a, t_nodes **b);
void		ft_check_av(int argc, char **argv);
void		swap_two(t_nodes **lst);
void		swap_three(t_nodes **lst);
void		swap_four(t_nodes **lst, t_nodes **lst_b, int a);
void		swap_five(t_nodes **lst, t_nodes **lst_b);
void		free_argv(char **str);
int			is_sorted(t_nodes *list);
long long	ft_atol(const char *str);
int			get_max_bits(t_nodes *a);
void		end(t_nodes *lst);
int			count_digit(char *str);
#endif
