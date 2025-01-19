/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:59:46 by yalp              #+#    #+#             */
/*   Updated: 2025/01/19 17:15:49 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 1;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			k = -1;
		i++;
	}
	while ((str[i] <= 57 && str[i] >= 48))
	{
		j = j * 10 + (str[i] - 48);
		i++;
	}
	return (k * j);
}

int ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst ->next != NULL)
	{
		lst = lst -> next;
	}
	return (lst->content);
}