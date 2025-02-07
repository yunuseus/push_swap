/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:10:56 by yalp              #+#    #+#             */
/*   Updated: 2025/02/07 15:18:14 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"

void	rr(t_list **a, t_list **b)
{
	t_list	*tmp_a;
	t_list	*head_a;
	t_list	*tmp_b;
	t_list	*head_b;

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

void	rra(t_list **a, int b)
{
	t_list	*last;
	t_list	*bflast;

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
	if (b == 1)
		ft_printf("%s\n", "rra");
}

void	rrb(t_list **b, int c)
{
	t_list	*last;
	t_list	*bflast;

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

void	rrr(t_list *a, t_list *b)
{
	rra(&a, 0);
	rrb(&b, 0);
	ft_printf("%s\n", "rrr");
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	ft_printf("%s\n", "pa");
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	ft_printf("%s\n", "pb");
}
