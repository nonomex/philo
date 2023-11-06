/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:54:21 by aammirat          #+#    #+#             */
/*   Updated: 2023/11/06 17:33:17 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	initfork(t_table	*table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		table->philo[i].forkleftlock = &table->islock[i];
		table->philo[i].forkleft = &table->fork[i];
		if (i + 1 < table->nb_philo)
		{
			table->philo[i].forkrightlock = &table->islock[i];
			table->philo[i].forkright = &table->fork[i + 1];
		}
		else
		{
			table->philo[i].forkrightlock = &table->islock[0];
			table->philo[i].forkright = &table->fork[0];
		}
		i++;
	}
	return (1);
}

int	inithuman(t_table *table)
{
	int	i;

	i = -1;
	table->philo = malloc (sizeof(t_philo) * table->nb_philo);
	if (!table->philo)
		return (0);
	table->whereinit++;
	while (++i < table->nb_philo)
	{
		table->philo[i].id = i;
		table->philo[i].time_die = table->time_die;
		table->philo[i].time_sleep = table->time_sleep;
		table->philo[i].time_eat = table->time_eat;
		table->philo[i].numberoftime = table->numberoftime;
		table->philo[i].start_time = table->start_time;
		table->philo[i].last_time_eat = 0;
		table->philo[i].writ = &table->writ;
		table->philo[i].isdead = &table->isdead;
		table->philo[i].isded = &table->isded;
		table->philo[i].number = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		if (pthread_mutex_init(&table->philo[i].number, NULL) != 0)
			return (0);
		table->philo[i].locked = &table->locked;
	}
	i = 0;
	return (initfork(table));
}

int	initmutex(t_table *table)
{
	int	i;

	i = 0;
	if (table->nb_philo == 1)
	{
		printf("0 1 has taken a fork\n");
		usleep(table->time_die * 1000);
		printf ("%d 1 died\n", table->time_die);
		return (-1);
	}
	else
	{
		table->isdead = 0;
		table->fork = malloc (sizeof(pthread_mutex_t) * table->nb_philo);
		if (!table->fork)
			return (0);
		table->islock = malloc (sizeof(int) * table->nb_philo);
		if (!table->islock)
			return (0);
		table->whereinit++;
		while (i < table->nb_philo)
		{
			table->islock[i] = 0;
			table->fork[i] = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
			if (pthread_mutex_init(&table->fork[i], NULL) != 0)
				return (0);
			table->whereinit++;
			i++;
		}
		table->writ = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		if (pthread_mutex_init(&table->writ, NULL) != 0)
			return (0);
		table->isded = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		if (pthread_mutex_init(&table->isded, NULL) != 0)
			return (0);
		table->locked = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		if (pthread_mutex_init(&table->locked, NULL) != 0)
			return (0);
		table->tred = malloc (sizeof(pthread_t) * table->nb_philo);
		if (!table->tred)
			return (0);
		table->whereinit += 10;
		return (inithuman(table));
	}
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
		return (initmutex(table));
	return (0);
}
