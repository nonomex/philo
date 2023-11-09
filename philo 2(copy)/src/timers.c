/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:54:53 by aammirat          #+#    #+#             */
/*   Updated: 2023/11/08 15:02:06 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	get_time(void)
{
	t_time	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	is_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->lastime);
	if ((get_time() - philo->start_time) - \
		philo->last_time_eat > philo->time_die)
	{
		pthread_mutex_unlock(&philo->lastime);
		if (*philo->isdead == 0)
		{
			pthread_mutex_lock(philo->writ);
			printf("%d %d died\n", \
				get_time() - philo->start_time, philo->id + 1);
			pthread_mutex_unlock(philo->writ);
			pthread_mutex_lock(philo->isded);
			*philo->isdead = 1;
			pthread_mutex_unlock(philo->isded);
		}
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&philo->lastime);
		return (0);
	}
}

void	writing(char	*str, t_philo	*philo)
{
	pthread_mutex_lock(philo->writ);
	pthread_mutex_lock(philo->isded);
	if (*philo->isdead == 0)
		printf ("%d %d %s", get_time() - philo->start_time, philo->id + 1, str);
	pthread_mutex_unlock(philo->isded);
	pthread_mutex_unlock(philo->writ);
}

void	goeat(t_philo *philo)
{
	writing("is eating\n", philo);
	pthread_mutex_lock(&philo->number);
	if (philo->numberoftime >= 0)
		philo->numberoftime--;
	pthread_mutex_unlock(&philo->number);
	usleep(philo->time_eat * 1000);
}
