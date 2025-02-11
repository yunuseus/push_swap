/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   too_many_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:05:50 by yalp              #+#    #+#             */
/*   Updated: 2025/02/11 16:52:53 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	get_max_bits(t_nodes *a)
{
	int		max_bit;
	int		max;
	t_nodes	*head;

	head = a;
	max = head->index;
	max_bit = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

int	is_sorted(t_nodes *list)
{
	t_nodes	*tmp;
	int		ret;

	tmp = list;
	ret = 0;
	while (list->next)
	{
		if (list->content > list->next->content)
		{
			ret = 1;
		}
		list = list->next;
	}
	list = tmp;
	return (ret);
}

long long	ft_atol(const char *str)
{
	long long	i;
	long long	sign;
	long long	res;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * sign);
}

t_nodes	*ft_lstnew(int content)
{
	t_nodes	*new;

	new = malloc(sizeof(t_nodes));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}

void	ft_lstadd_front(t_nodes **lst, t_nodes *new)
{
	if (lst && new)
	{
		new -> next = *lst;
		*lst = new;
	}
}
