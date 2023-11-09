/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:56:16 by aammirat          #+#    #+#             */
/*   Updated: 2023/11/08 15:39:52 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct timeval	t_time;

typedef struct s_philo {
	int				time_eat;
	int				time_sleep;
	int				time_die;
	int				start_time;
	int				id;
	pthread_mutex_t	*writ;
	int				last_time_eat;
	int				numberoftime;
	pthread_mutex_t	number;
	int				*isdead;
	pthread_mutex_t	*forkleft;
	int				*forkleftlock;
	pthread_mutex_t	*forkright;
	int				*forkrightlock;
	pthread_mutex_t	*isded;
	pthread_mutex_t	lastime;
}			t_philo;

typedef struct s_table {
	t_philo			*philo;
	int				*islock;
	pthread_mutex_t	*fork;
	pthread_mutex_t	writ;
	pthread_mutex_t	isded;
	pthread_t		*tred;
	int				nb_philo;
	int				start_time;
	int				time_eat;
	int				time_sleep;
	int				time_die;
	int				numberoftime;
	int				whereinit;
	int				isdead;
}			t_table;

int		ft_atoi(char *str, char *error);
int		only_int(char *str);
int		get_time(void);
int		initphilo(int c, char **str, t_table *table);
void	freephilo(t_table *table);
int		is_died(t_philo *philo);
void	writing(char	*str, t_philo	*philo);
void	goeat(t_philo *philo);
int		eatingodd(t_philo *philo);
int		eatingeven(t_philo *philo);
void	next(t_philo *philo);
int		onlyone(t_table *table);

#endif
