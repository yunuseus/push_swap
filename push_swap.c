/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:58:31 by yalp              #+#    #+#             */
/*   Updated: 2025/02/02 20:08:44 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (list)
	{
		if (list->index > list->next->index)
		{
			list = tmp;
			return (0);
		}
		list = list->next;
	}
	list = tmp;
	return (1);
}

t_list	*find_next_min(t_list *list)
{
	int		a;
	t_list	*tmp;

	a = 2147483647;
	tmp = list;
	while (list)
	{
		if (list->content < a && list->index == -1)
			a = list->content;
		list = list->next;
	}
	list = tmp;
	while (list)
	{
		if (list->content == a)
			return (list);
		list = list->next;
	}
	return(tmp);
}
void	indexter(t_list *list) 
{
	int		i;
	t_list 	*head;
	t_list *x = list;
	while (list)
	{
		list->index = -1;
		list = list->next;
	}
	list = x;

	i = 0;
	head = list;
	while (list)
	{
		list = find_next_min(list);
		list->index = i;
		i++;
	}
	list = head;
	
}

void radix(t_list *a, t_list *b)
{
	t_list *tmp;

	int lstsize = ft_lstsize(a);	
	tmp = a;
	int i = 0;
	int b_size;
	int reset = 0;
	while (!is_sorted(a)) // i < 8
	{
		reset = 0;
		while (reset < lstsize)
		{
			if ((a->index >> i) & 1)
				ra(&a);
			else
				pb(&a, &b);
			reset++;
		}
		reset = -1;
		b_size = ft_lstsize(b);
		while (++reset < b_size)
			pa(&a, &b);
		i++;
	}
	a = tmp;
}

int	main(int argc, char ** argv)
{
	t_list *a;
	t_list *b;
	b = malloc(sizeof(t_list) * 1);
	int i = 2;
	a = ft_lstnew(ft_atoi(argv[1]));
	while (i < argc)
	{
		ft_lstadd_back(&a,ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	radix(a, b);
	ft_lst_free(a);	
}
