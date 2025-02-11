/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:10:56 by yalp              #+#    #+#             */
/*   Updated: 2025/02/11 16:59:44 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include "printf/ft_printf.h"

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

void	sa(t_nodes **a)
{
	t_nodes	*tmp;

	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
	ft_printf("%s\n", "sa");
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
