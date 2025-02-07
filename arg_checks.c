/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:16:57 by yalp              #+#    #+#             */
/*   Updated: 2025/02/07 16:34:06 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

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

void put_error(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

int	ft_is_num(char *nb)
{
	int	i;

	i = 0;
	if (nb[0] == '\0')
		put_error();
	if (nb[0] == ' ')
		put_error();
	return (1);
}

void	free_argv(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i]);
	free(str);
}

int	ft_is_same(int nb, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == nb)
			return (1);
		i++;
	}
	return (0);
}

void 	ft_check_av(int argc, char **argv)
{
	long long	number;
	char		**args;
	int			i;
	
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;;
		args = argv;
	}
	while (args[i])
	{
		if (!(ft_is_num(argv[i])))
			put_error();
		number = ft_atol(argv[i]);
		if (number < -2147483648 || number > 2147483647)
			put_error();
		if (ft_is_same(number, args, i))
			put_error();
		i++;
	}
	if (argc == 2)
		free_argv(argv);
}