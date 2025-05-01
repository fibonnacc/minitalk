/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 02:59:07 by helfatih          #+#    #+#             */
/*   Updated: 2025/03/16 01:01:25 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

int	exp_2(int n)
{
	int	result;

	result = 1;
	while (n != 0)
	{
		result *= 2;
		n--;
	}
	return (result);
}

int	ft_atoi(char *str)
{
	int	res;
	int	i;

	if (!str)
		exit(1);
	i = 0;
	if (str[i] == '-')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}
