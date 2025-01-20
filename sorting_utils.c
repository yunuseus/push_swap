/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:10:56 by yalp              #+#    #+#             */
/*   Updated: 2025/01/19 17:17:44 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	t_list	*tmp;

	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
}
void	sb(t_list **b)
{
	t_list *tmp;

	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = *b;
	*b = tmp;
}
void	ss(t_list *a, t_list *b)
{
	sa(&a);
	sb(&b);
}
void	ra(t_list **a)
{
	t_list	*tmp;
	t_list	*head;
	tmp = *a;
	*a = (*a)->next;
	head = *a;
	tmp->next = NULL;
	ft_lstadd_back(&head, tmp);
}
void	rb(t_list **b)
{
	t_list	*tmp;
	t_list	*head;

	tmp = *b;
	*b = (*b)->next;
	head = *b;
	tmp->next = NULL;
	ft_lstadd_back(&head, tmp);
}
void	rr(t_list *a, t_list *b)
{
	ra(&a);
	rb(&b);
}

void	rra(t_list **a)
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
}
void	rrb(t_list **b)
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
}
void	rrr(t_list *a, t_list *b)
{
	rra(&a);
	rrb(&b);
}
void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}
void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}
