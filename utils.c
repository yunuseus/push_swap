/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:59:46 by yalp              #+#    #+#             */
/*   Updated: 2025/02/10 17:17:51 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_nodes *lst)
{
	int		i;
	t_nodes	*tmp;

	tmp = lst;
	i = 0;
	while (lst)
	{
		i++;
		lst = lst -> next;
	}
	lst = tmp;
	return (i);
}

void	ft_lst_free(t_nodes *list)
{
	t_nodes	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

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

t_nodes	*ft_lstlast(t_nodes *lst)
{
	if (!lst)
		return (NULL);
	while (lst ->next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}

void	ft_lstadd_back(t_nodes **lst, t_nodes *new)
{
	t_nodes	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp -> next = new;
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
