/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:02:02 by yalp              #+#    #+#             */
/*   Updated: 2025/02/11 14:46:13 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_two(t_nodes **lst)
{
	if ((*lst)->content > (*lst)->next->content)
		sa(lst);
}

void	swap_three(t_nodes **lst)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*lst)->content;
	n2 = (*lst)->next->content;
	n3 = (*lst)->next->next->content;
	if (n1 > n2 && n2 > n3)
	{
		sa(lst);
		rra(lst);
	}
	else if (n1 > n2 && n1 > n3 && n2 < n3)
		ra(lst);
	else if (n1 > n2 && n1 < n3)
		sa(lst);
	else if (n1 < n2 && n1 > n3)
		rra(lst);
	else if (n1 < n2 && n2 > n3)
	{
		rra(lst);
		sa(lst);
	}
}

void	swap_four(t_nodes **lst, t_nodes **lst_b, int a)
{
	int c;

	c = a;
	while ((*lst)->index != a)
		ra(lst);
	pb(lst, lst_b);
	swap_three(lst);
	pa(lst, lst_b);
}

void	swap_five(t_nodes **lst, t_nodes **lst_b)
{
	t_nodes	*tmp;
	int		i;

	i = 0;
	tmp = *lst;
	while (tmp->index != 0)
	{
		tmp = tmp->next;
		i++;
	}
	if (i == 4)
		rra(lst);
	while ((*lst)->index != 0)
		ra(lst);
	pb(lst, lst_b);
	swap_four(lst, lst_b, 1);
	pa(lst, lst_b);
}
