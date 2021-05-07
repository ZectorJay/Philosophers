/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_started.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:50:05 by hmickey           #+#    #+#             */
/*   Updated: 2021/05/07 12:02:08 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 1 аргумент - кол-во пидорасов и вилок
** 2 аргумент - времени шоб сдохнуть (в милипиписьках. Если не похавает до этого времени, то сдохнет, пидор)
** 3 аргумент - времени на жратву. В это время эти пидорасы занимают 2 вилки и остальные не могут пожрать.
** 4 аргумент - Времени на сон. Так же в милипиписьках
** 5 аргумент - НЕ ОБЯЗАТЕЛЬНЫЙ. Сколько минимум раз должны пожрать пидорасы. ЕСЛИ НЕ ЗАДАН - то симуляция будет ебашить пока кто-нибудь из этих пидорасов не сдохнет.
*/


#include "philo_one.h"

pthread_mutex_t	left;
pthread_mutex_t	right;
int	forks_counter;

void	*start_life(void *get_info)
{
	t_all *all;

	all = (t_all *)get_info;
	printf("%ld ms | Philo %d has started his useless existance\n", check_time(), all->philo[all->num].num);
	if (all->philo[all->num].num % 2 == 0)
		sleep(1);
	printf("%ld ms | philo %d died\n", check_time(), all->philo[all->num].num);	
	return NULL;
}

void	start_philo(pthread_t *thread_num, char **argv, t_all *all)
{
	printf("limit - %d\n", all->info.philo_num);
	while (++all->num < all->info.philo_num)
	{
		pthread_create(&thread_num[all->info.num], NULL, start_life, all);
		usleep(10);
	}
	all->num = -1;
	while (++all->num < all->info.philo_num)
		pthread_join(thread_num[all->info.num], NULL);
	// pthread_mutex_destroy(&left);
	// pthread_mutex_destroy(&right);
}

void	check_args(int argc, char **argv, t_info *info)
{
	if (argc != 5 && argc != 6)
	{
		printf("Dude, not enough args. Fix it.\n");
		exit (0);
	}
	info->times_eat = -1;
	info->philo_num = ft_atoi(argv[1]);
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

void	init_philo(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->info.philo_num)
	{
		all->philo[i].death_timer = 0;
		all->philo[i].num = i;
		all->philo[i].status = 0;
	}
}

int main(int argc, char **argv)
{
	pthread_t	*philo;
	t_all		all;

	check_args(argc, argv, &all.info);
	// pthread_mutex_init(&left, NULL);
	// pthread_mutex_init(&right, NULL);
	philo = malloc(all.info.philo_num);
	all.philo = malloc(all.info.philo_num);
	if (!philo || !all.philo)
		printf("Error during allocating memory\n");
	else
	{
		init_philo(&all);
		all.num = -1;
		gettimeofday(&g_start, 0); 
		start_philo(philo, argv, &all);
		free(philo);
	}
	exit (0);
}