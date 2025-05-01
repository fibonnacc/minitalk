/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:40:55 by helfatih          #+#    #+#             */
/*   Updated: 2025/03/14 23:47:51 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar(nb % 10 + 48);
}

void	receiver1(int signal, siginfo_t *info, void *context)
{
	static int		count_bit;
	static char		i;
	static pid_t	last_pid;
	int				bit;

	(void)context;
	if (last_pid != 0 && last_pid != info->si_pid)
	{
		count_bit = 0;
		i = 0;
	}
	last_pid = info->si_pid;
	bit = 0;
	if (signal == SIGUSR1)
		bit = 1;
	i += bit * exp_2(count_bit);
	count_bit++;
	if (count_bit == 8)
	{
		write(1, &i, 1);
		count_bit = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid;

	(void)av;
	if (ac != 1)
	{
		exit(1);
	}
	pid = getpid();
	write(1, "ID : ", 5);
	ft_putnbr(pid);
	write(1, "\n", 1);
	sa.sa_sigaction = receiver1;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	while (1)
	{
		pause();
	}
}
