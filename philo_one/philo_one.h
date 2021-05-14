/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 07:14:28 by hmickey           #+#    #+#             */
/*   Updated: 2021/05/14 10:32:13 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

pthread_mutex_t	g_output;

typedef struct s_info
{
	int			life_time;
	int			times_eat;
	int			eating_timer;
	int			sleeping_timer;
	int			philo_num;
	int			num;
}				t_info;

typedef struct s_philo
{
	long			start_timer;
	t_info			*info;
	int				eating_timer;
	int				sleeping_timer;
	int				num;
	long int		previous_meal;
	long int		death_timer;
	long int		current_meal;
	pthread_mutex_t	left;
	pthread_mutex_t	*right;
	int				times_eat;
}				t_philo;

typedef struct s_all
{
	t_philo		*philo;
	t_info		inf;
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
void		*philo_status(t_all *all, int num, int **array, int flag);
void		eat_sleep_think_loop(t_philo *philo, int flag);
int			*init_variables(t_all *all, int *k);
void		*detach_and_destroy(pthread_t *thread_num, t_all *all);

#endif