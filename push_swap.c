/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:58:31 by yalp              #+#    #+#             */
/*   Updated: 2025/02/11 15:06:57 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	fill_stack(t_nodes **a, char **argv, int argc)
{
	int		i;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = argv;
		i++;
	}
	*a = ft_lstnew(ft_atoi(args[i++]));
	while (args[i])
		ft_lstadd_back(a, ft_lstnew(ft_atoi(args[i++])));
	if (argc == 2)
		free_argv(args);
}

t_nodes	*find_next_min(t_nodes **list)
{
	long	a;
	t_nodes	*tmp;

	a = 2147483648;
	tmp = *list;
	while (tmp)
	{
		if (tmp->content < a && tmp->index == -1)
			a = tmp->content;
		tmp = tmp->next;
	}
	tmp = *list;
	while (tmp)
	{
		if (tmp->content == a)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	indexer(t_nodes **list)
{
	int		i;
	t_nodes	*head;
	t_nodes	*x;

	head = *list;
	while (*list)
	{
		(*list)->index = -1;
		*list = (*list)->next;
	}
	*list = head;
	i = 0;
	head = *list;
	x = find_next_min(list);
	while (x)
	{
		x->index = i++;
		x = find_next_min(list);
	}
	*list = head;
}

void	radix(t_nodes **a, t_nodes *b)
{
	t_nodes	*tmp;
	int		lstsize;
	int		i;
	int		reset;
	int		max_bit;

	tmp = *a;
	lstsize = ft_lstsize(*a);
	i = 0;
	max_bit = get_max_bits(*a);
	while (i < max_bit)
	{
		reset = 0;
		while (reset++ < lstsize)
		{
			tmp = *a;
			if (((*a)->index >> i) & 1)
				ra(a);
			else
				pb(a, &b);
		}
		while (ft_lstsize(b) != 0)
			pa(a, &b);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_nodes	*a;
	t_nodes	*b;
	int		i;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	ft_check_av(argc, argv);
	fill_stack(&a, argv, argc);
	indexer(&a);
	if (is_sorted(a) == 0)
		argc = 7;
	else if (argc == 3)
		swap_two(&a);
	else if (argc == 4)
		swap_three(&a);
	else if (argc == 5)
		swap_four(&a, &b, 0);
	else if (argc == 6)
		swap_five(&a, &b);
	else
		radix(&a, b);
	ft_lst_free(a);
}
