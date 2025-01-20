/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:58:31 by yalp              #+#    #+#             */
/*   Updated: 2025/01/19 17:36:44 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char ** argv)
{
	t_list *a;
	int i = 2;
	a = ft_lstnew(ft_atoi(argv[1]));
	while (i < argc)
	{
		ft_lstadd_back(&a,ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	rra(&a);
	while (a != NULL)
	{
		printf("%d", a->content);
		a = a->next;
	}
	

	

	
}