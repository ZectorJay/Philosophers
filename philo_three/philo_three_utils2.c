/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:53:53 by hmickey           #+#    #+#             */
/*   Updated: 2021/05/14 19:10:00 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long)(time.tv_sec * 1000 + time.tv_usec / 1000));
}

void	my_usleep(long time)
{
	long	t;

	t = get_time();
	while (get_time() - t < time)
		usleep(100);
}

void	ft_putstr(char *str) // МОЖНО УДАЛИТЬ!
{
	write (1, str, ft_strlen(str));
}

void	init_philo(t_all *all)
{
	all->philo.status = 0;
	all->philo.current_meal = 0;
	all->philo.death_timer = 0;
	all->philo.num = 0;
	all->philo.times_eat = 0;
	all->philo.eating_timer = all->inf.eating_timer;
	all->philo.sleeping_timer = all->inf.sleeping_timer;
	all->philo.info = &all->inf;
	all->philo.sem = &all->sem;
}

void	check_args(int argc, char **argv, t_info *info)
{
	if (argc != 5 && argc != 6)
	{
		printf("Dude, wrong args number. Fix it.\n");
		exit (0);
	}
	info->times_eat = -1;
	info->philo_num = ft_atoi(argv[1]);
	if (info->philo_num == 1)
	{
		printf("Dude, one philosoper mean one fork. He can't eat with 1 fork.");
		exit (0);
	}
	info->life_time = ft_atoi(argv[2]);
	info->eating_timer = ft_atoi(argv[3]);
	info->sleeping_timer = ft_atoi(argv[4]);
	info->num = -1;
	if (argc == 6)
		info->times_eat = ft_atoi(argv[5]);
	if (info->philo_num <= 0 || info->life_time <= 0 || info->eating_timer <= 0
		|| info->sleeping_timer <= 0 || info->times_eat == 0)
	{
		printf("Dude, you type something weird in args. Check and fix it.");
		exit (0);
	}
}
