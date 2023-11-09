/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:12:09 by aammirat          #+#    #+#             */
/*   Updated: 2023/11/08 15:41:56 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	only_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

int	test_sizeint(unsigned int c)
{
	if (c >= 2147483648)
		return (1);
	return (0);
}

int	ft_atoi(char *str, char *error)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		if (test_sizeint((unsigned)res * 10 + (str[i] - 48)))
			error[0] = 'o';
		res = res * 10;
		res = res + str[i] - 48;
		i++;
	}
	return (res);
}

int	onlyone(t_table *table)
{
	printf("0 1 has taken a fork\n");
	usleep(table->time_die * 1000);
	printf ("%d 1 died\n", table->time_die);
	return (-1);
}
