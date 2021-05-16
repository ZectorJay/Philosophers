/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:16:15 by hmickey           #+#    #+#             */
/*   Updated: 2021/05/16 14:46:12 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/time.h>
#include <pthread.h>
#include <signal.h>

typedef struct s_info
{
	int			life_time;
	int			times_eat;
	int			eating_timer;
	int			sleeping_timer;
	int			philo_num;
	int			num;
}				t_info;

typedef struct s_semaph
{
	sem_t		*forks;
	sem_t		*meals;
	sem_t		*status;
	sem_t		*output;
}				t_semaph;

typedef struct s_philo
{
	t_info			*info;
	t_semaph		*sem;
	long			start_timer;
	int				eating_timer;
	int				sleeping_timer;
	int				num;
	long int		death_timer;
	long int		current_meal;
	int				times_eat;
	int				status;
}				t_philo;

typedef struct s_all
{
	t_philo		philo;
	t_info		inf;
	t_semaph	sem;
	pid_t		*pid;
	int			num;
	long		start;
}				t_all;

long int	ft_atoi(const char *str);
void		ft_putnbr(long int n);
void		ft_putstr(char *str);
void		init_philo(t_all *all);
void		my_usleep(long time);
long		get_time(void);
void		check_args(int argc, char **argv, t_info *info);
void		thinking(t_philo *philo);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
int			ft_strlen(char *str);
int			intchr(int *row, int find);
void		type_message(int num, int timer, char *message);
void		*philo_status(t_all *all, int num, int flag);
void		eat_sleep_think_loop(t_philo *philo, int flag);
void		*detach_and_destroy(pthread_t *thread_num, t_all *all);
int			init_semaphors(t_all *all);
void		*spy_himself(void *get_info);
void		*check_death(void *get_info);
#endif