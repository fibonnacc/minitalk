/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:37:13 by helfatih          #+#    #+#             */
/*   Updated: 2025/03/16 01:25:06 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

int	g_handle = 0;

void	fun_handle(int sig)
{
	if (sig == SIGUSR1)
		g_handle = 1;
}

void	ft_shift(int pid, char *str)
{
	int (i), j, ret;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			if (((str[i] >> j) & 1) == 1)
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
		i++;
	}
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
		return (1);
	}
	signal(SIGUSR1, fun_handle);
	pid = ft_atoi(av[1]);
	ft_shift(pid, av[2]);
}
