/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 07:14:28 by hmickey           #+#    #+#             */
/*   Updated: 2021/05/15 15:37:04 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <fcntl.h>
# include <semaphore.h>
# include <sys/types.h>

# define RED            "\033[1;31m"
# define RESET          "\033[0m"
# define YELLOW         "\033[1;33m"

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
	long int		previous_meal;
	long int		death_timer;
	long int		current_meal;
	int				times_eat;
}				t_philo;

typedef struct s_all
{
	t_philo		*philo;
	t_info		inf;
	t_semaph	sem;
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
int			init_semaphors(t_all *all);
#endif