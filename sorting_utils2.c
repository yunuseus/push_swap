/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:13:51 by yalp              #+#    #+#             */
/*   Updated: 2025/02/08 13:22:09 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"

void	sa(t_nodes **a)
{
	t_nodes	*tmp;

	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
	ft_printf("%s\n", "sa");
}

void	sb(t_nodes **b)
{
	t_nodes	*tmp;

	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = *b;
	*b = tmp;
	ft_printf("%s\n", "sb");
}

void	ss(t_nodes **a, t_nodes **b)
{
	t_nodes	*tmp_a;
	t_nodes	*tmp_b;

	tmp_a = (*a)->next;
	(*a)->next = tmp_a->next;
	tmp_a->next = *a;
	*a = tmp_a;
	tmp_b = (*b)->next;
	(*b)->next = tmp_b->next;
	tmp_b->next = *b;
	*b = tmp_b;
	ft_printf("%s", "ss");
}

void	ra(t_nodes **a)
{
	t_nodes	*tmp;
	t_nodes	*head;

	tmp = *a;
	*a = (*a)->next;
	head = *a;
	tmp->next = NULL;
	ft_lstadd_back(&head, tmp);
	ft_printf("%s\n", "ra");
}

void	rb(t_nodes **b)
{
	t_nodes	*tmp;
	t_nodes	*head;

	tmp = *b;
	*b = (*b)->next;
	head = *b;
	tmp->next = NULL;
	ft_lstadd_back(&head, tmp);
	ft_printf("%s\n", "rb");
}