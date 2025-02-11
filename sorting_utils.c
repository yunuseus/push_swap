/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:10:56 by yalp              #+#    #+#             */
/*   Updated: 2025/02/11 14:01:18 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"

void	rr(t_nodes **a, t_nodes **b)
{
	t_nodes	*tmp_a;
	t_nodes	*head_a;
	t_nodes	*tmp_b;
	t_nodes	*head_b;

	tmp_a = *a;
	*a = (*a)->next;
	head_a = *a;
	tmp_a->next = NULL;
	ft_lstadd_back(&head_a, tmp_a);
	tmp_b = *b;
	*b = (*b)->next;
	head_b = *b;
	tmp_b->next = NULL;
	ft_lstadd_back(&head_b, tmp_b);
	ft_printf("%s\n", "rr");
}

void	rra(t_nodes **a)
{
	t_nodes	*last;
	t_nodes	*bflast;

	last = *a;
	bflast = NULL;
	while (last->next)
	{
		bflast = last;
		last = last->next;
	}
	if (bflast)
		bflast->next = NULL;
	last->next = *a;
	*a = last;
	ft_printf("%s\n", "rra");
}

void	rrb(t_nodes **b, int c)
{
	t_nodes	*last;
	t_nodes	*bflast;

	last = *b;
	bflast = NULL;
	while (last->next)
	{
		bflast = last;
		last = last->next;
	}
	if (bflast)
		bflast->next = NULL;
	last->next = *b;
	*b = last;
	if (c == 1)
		ft_printf("%s\n", "rrb");
}



void	pa(t_nodes **a, t_nodes **b)
{
	t_nodes	*tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	ft_printf("%s\n", "pa");
}

void	pb(t_nodes **a, t_nodes **b)
{
	t_nodes	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	ft_printf("%s\n", "pb");
}
