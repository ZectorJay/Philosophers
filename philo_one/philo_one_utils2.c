/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:53:53 by hmickey           #+#    #+#             */
/*   Updated: 2021/05/14 10:15:05 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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
		usleep(1);
}

void	ft_putstr(char *str)
{
	write (1, str, ft_strlen(str));
}

void	init_philo(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->inf.philo_num)
	{
		pthread_mutex_init(&all->philo[i].left, NULL);
		all->philo[i].previous_meal = 0;
		all->philo[i].current_meal = 0;
		all->philo[i].death_timer = 0;
		all->philo[i].num = i;
		all->philo[i].times_eat = 0;
		all->philo[i].eating_timer = all->inf.eating_timer;
		all->philo[i].sleeping_timer = all->inf.sleeping_timer;
		all->philo[i].info = &all->inf;
	}
	all->philo[i - 1].right = &all->philo[0].left;
	i = 0;
	while (i < all->inf.philo_num - 1)
	{
		all->philo[i].right = &all->philo[i + 1].left;
		i++;
	}
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
