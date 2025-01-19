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
void sa(t_list *a)
{
	int tmp;
	tmp = a->next->content;
	a->next->content = a->content;
	a->content = tmp;
	
}
void ra(t_list *a)
{
	int tmpl;
	int tmpf;
	tmpl = ft_lstlast(a);
	tmpf = a->content;
	a[len - 1] = a[0];
	while (i < len -2)
	{	
		a[i] = a[i + 1];
		i++;
	}
	a[len -2] = tmp;
}
void rra(int *a, int len)
{
	int tmp;
	int i = len -1;
	tmp = a[len -1];
	while (0 < i)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = tmp;
}