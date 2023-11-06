/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:56:07 by aammirat          #+#    #+#             */
/*   Updated: 2023/11/06 18:01:16 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*philothread(void	*take)
{
	t_philo	*philo;

	philo = (t_philo *)take;
	pthread_mutex_lock(philo->isded);
	while (*philo->isdead == 0 && philo->numberoftime != 0)
	{
		pthread_mutex_unlock(philo->isded);
		pthread_mutex_lock(philo->locked);
		if (*philo->forkleftlock == 0 && *philo->forkrightlock == 0)
		{
			
			*philo->forkleftlock = 1;
			*philo->forkrightlock = 1;
			pthread_mutex_lock(philo->forkleft);
			writing ("has taken a fork\n", philo);
			pthread_mutex_lock(philo->forkright);
			writing ("has taken a fork\n", philo);
			goeat(philo);
			pthread_mutex_unlock(philo->forkleft);
			pthread_mutex_unlock(philo->forkright);
			*philo->forkleftlock = 0;
			*philo->forkrightlock = 0;
		}
		pthread_mutex_unlock(philo->locked);
		pthread_mutex_lock(philo->isded);
	}
	pthread_mutex_unlock(philo->isded);
	return (NULL);
}

int	ntime(t_table *table)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (i < table->nb_philo)
	{
		pthread_mutex_lock(&table->philo[i].number);
		nb += table->philo[i].numberoftime;
		pthread_mutex_unlock(&table->philo[i].number);
		i++;
	}
	return (nb);
}

void	startphilo(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nb_philo)
		pthread_create(&table->tred[i], NULL, philothread, &table->philo[i]);
	pthread_mutex_lock(&table->isded);
	while(table->isdead != 1 && ntime(table) != 0)
	{
		pthread_mutex_unlock(&table->isded);
		i = -1;
		while (++i < table->nb_philo && table->isdead != 1)
			is_died(&table->philo[i]);
		pthread_mutex_lock(&table->isded);
	}
	pthread_mutex_unlock(&table->isded);
	i = -1;
	while (i < table->nb_philo)
		pthread_join(table->tred[i], NULL);
}

int	main(int argc, char *argv[])
{
	t_table	table;
	int		g;

	if (argc != 5 && argc != 6)
		write (1, "Error\nInvalid number of arguments\n", 35);
	else
	{
		g = initphilo(argc, argv, &table);
		if (g == 1)
		{
			startphilo(&table);
			freephilo(&table);
		}
		else if (g == 0)
		{
			freephilo(&table);
			return (1);
		}
	}
	return (0);
}
