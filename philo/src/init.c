/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:54:21 by aammirat          #+#    #+#             */
/*   Updated: 2023/10/30 14:43:54 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	initmutex(t_table *table)
{
	int	i;

	i = 0;
	table->fork = malloc (sizeof(pthread_mutex_t) * table->nb_philo);
	if (!table->fork)
		return (0);
	table->whereinit++;
	while (i < table->nb_philo)
	{
		table->fork[i] = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		if (pthread_mutex_init(&table->fork[i], NULL) != 0)
			return (0);
		table->whereinit++;
		i++;
	}
	return (1);
}

int	inithuman(t_table *table)
{
	int	i;

	i = 0;
	table->philo = malloc (sizeof(t_philo) * table->nb_philo);
	if (!table->philo)
		return (0);
	table->whereinit++;
	while (i < table->nb_philo)
	{
		table->philo[i].id = i;
		table->philo[i].time_die = table->time_die;
		table->philo[i].time_sleep = table->time_sleep;
		table->philo[i].time_eat = table->time_eat;
		table->philo[i].numberoftime = table->numberoftime;
		i++;
	}
	i = 0;
	return (initmutex(table));
}

int	initphilo(int c, char **str, t_table *table)
{
	int		i;
	char	error[1];

	i = 0;
	error[0] = 'n';
	while (++i < c)
		if (only_int(str[i]) == 1)
			error[0] = 'y';
	table->nb_philo = ft_atoi(str[1], error);
	table->time_die = ft_atoi(str[2], error);
	table->time_eat = ft_atoi(str[3], error);
	table->time_sleep = ft_atoi(str[4], error);
	table->start_time = get_time();
	table->whereinit = 0;
	if (c == 6)
		table->numberoftime = ft_atoi(str[5], error);
	else
		table->numberoftime = -1;
	if (error[0] == 'y')
		write (1, "Error\nInput must be a positive int\n", 35);
	else if (error[0] == 'o')
		write (1, "Error\nInput overflow\n", 21);
	else
		return (inithuman(table));
	return (0);
}
