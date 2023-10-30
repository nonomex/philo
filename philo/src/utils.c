/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:12:09 by aammirat          #+#    #+#             */
/*   Updated: 2023/10/30 14:40:04 by aammirat         ###   ########lyon.fr   */
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

static void	ft_putchar_fd(char c)
{
	write (1, &c, 1);
}

int	ft_putnbr(int c)
{
	int	i;

	if (c == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (c < 0)
	{
		write (1, "-", 1);
		return (1 + ft_putnbr(c * -1));
	}
	else if (c < 10)
	{
		ft_putchar_fd(c + '0');
		return (1);
	}
	else
	{
		i = ft_putnbr(c / 10);
		ft_putchar_fd(c % 10 + 48);
		return (1 + i);
	}
}
