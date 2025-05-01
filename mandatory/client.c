/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:36:06 by helfatih          #+#    #+#             */
/*   Updated: 2025/03/15 23:45:21 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_handle = 0;

void	ft_shift(int pid, char *str)
{
	int (i), j, ret;
	i = -1;
	while (str[++i])
	{
		j = 0;
		while (j < 8)
		{
			if ((str[i] / exp_2(j)) % 2 == 1)
				ret = kill(pid, SIGUSR1);
			else
				ret = kill(pid, SIGUSR2);
			if (ret == -1)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			while (g_handle != 1)
				;
			g_handle = 0;
			j++;
		}
	}
}

void	ft_handle(int sig)
{
	if (sig == SIGUSR1)
		g_handle = 1;
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!is_number(av[1]))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	signal(SIGUSR1, ft_handle);
	pid = ft_atoi(av[1]);
	ft_shift(pid, av[2]);
}
