/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:51:22 by aammirat          #+#    #+#             */
/*   Updated: 2023/11/07 15:45:23 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	eatingodd(t_philo *philo)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(philo->forkleft);
	pthread_mutex_lock(philo->forkright);
	if (*philo->forkleftlock == 0 && *philo->forkrightlock == 0)
	{
		*philo->forkleftlock = 1;
		*philo->forkrightlock = 1;
		writing ("has taken a fork\n", philo);
		writing ("has taken a fork\n", philo);
		goeat(philo);
		ret = 1;
		pthread_mutex_lock(&philo->lastime);
		philo->last_time_eat = get_time() - philo->start_time;
		pthread_mutex_unlock(&philo->lastime);
		*philo->forkleftlock = 0;
		*philo->forkrightlock = 0;
	}
	pthread_mutex_unlock(philo->forkleft);
	pthread_mutex_unlock(philo->forkright);
	return (ret);
}

int	eatingeven(t_philo *philo)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(philo->forkright);
	pthread_mutex_lock(philo->forkleft);
	if (*philo->forkleftlock == 0 && *philo->forkrightlock == 0)
	{
		*philo->forkleftlock = 1;
		*philo->forkrightlock = 1;
		writing ("has taken a fork\n", philo);
		writing ("has taken a fork\n", philo);
		goeat(philo);
		ret = 1;
		pthread_mutex_lock(&philo->lastime);
		philo->last_time_eat = get_time() - philo->start_time;
		pthread_mutex_unlock(&philo->lastime);
		*philo->forkleftlock = 0;
		*philo->forkrightlock = 0;
	}
	pthread_mutex_unlock(philo->forkleft);
	pthread_mutex_unlock(philo->forkright);
	return (ret);
}

void	next(t_philo *philo)
{
	writing("is sleeping\n", philo);
	usleep(philo->time_sleep * 1000);
	writing("is thinking\n", philo);
}
