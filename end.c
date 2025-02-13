/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:13:51 by yalp              #+#    #+#             */
/*   Updated: 2025/02/13 14:52:38 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	end(t_nodes *lst)
{
	ft_lst_free(lst);
	exit(1);
}

int	count_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
