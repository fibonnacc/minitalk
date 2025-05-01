/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:29:03 by helfatih          #+#    #+#             */
/*   Updated: 2025/03/13 02:27:23 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	receiver(int signal, siginfo_t *info, void *context);
void	receiver1(int signal, siginfo_t *info, void *context);
int		ft_atoi(char *str);
int		is_number(char *str);
void	ft_shift(int pid, char *str);
void	fun_handle(int sig);
int		exp_2(int n);

#endif