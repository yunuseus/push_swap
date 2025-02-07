/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:58:31 by yalp              #+#    #+#             */
/*   Updated: 2025/02/07 17:30:04 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_list **a, char **argv, int argc)
{
	int	i;

	i = 1;
	*a = ft_lstnew(ft_atoi(argv[i]));
	while  (++i < argc)
	{
		printf("%d\n", i);
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
	}
}

int	get_max_bits(t_list *a)
{
	int	max_bit;
	int max;
	t_list	*head;

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

int	is_sorted(t_list *list)
{
	t_list	*tmp;
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

t_list	*find_next_min(t_list **list)
{
	int		a;
	t_list	*tmp;
	t_list	**min_node;

	a = 2147483647;
	tmp = *list;
	while (*list)
	{
		if ((*list)->content < a && (*list)->index == -1)
			a = (*list)->content;
		*list = (*list)->next;
	}
	*list = tmp;
	while (*list)
	{
		if ((*list)->content == a)
			return (*list);
		*list = (*list)->next;
	}
	return(NULL);
}
void	indexer(t_list **list) 
{
	int		i;
	t_list 	*head;
	t_list *x;

	x = *list;
	while (*list)
	{
		(*list)->index = -1;
		*list = (*list)->next;
	}
	*list = x;

	i = 0;
	head = *list;
	while ((x = find_next_min(list)))
		x->index = i++;
	*list = head;
}

void radix(t_list *a, t_list *b)
{
	t_list	*tmp;
	int		lstsize;
	int		i;
	int		reset;
	int		max_bit;

	tmp = a;
	lstsize = ft_lstsize(a);
	i = 0;
	max_bit = get_max_bits(a);
	while (i < max_bit)
	{
		reset = 0;
		while (reset++ < lstsize)
		{
			tmp = a;
			if ((a->index >> i) & 1)
				ra(&a);
			else
				pb(&a, &b);
		}
		while (ft_lstsize(b) != 0)
			pa(&a, &b);
		i++;
	}
	a = tmp;

}

int	main(int argc, char ** argv)
{
	t_list	*a;
	t_list	*b;
	int		i;
	if (argc < 2)
		return (0);
	ft_check_av(argc, argv);
	fill_stack(&a, argv, argc);
	indexer(&a);
	radix(a, b);
}
