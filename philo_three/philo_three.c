/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:55:24 by hmickey           #+#    #+#             */
/*   Updated: 2021/05/14 19:23:31 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*odd_philo_num(t_all *all)
{
	pthread_t *thread;

	thread = malloc(sizeof(pthread_t));
	sem_wait(all->sem.status);
	pthread_create(thread, NULL, spy_himself, all);
	if (all->num % 2 == 0 && all->philo.num != all->inf.philo_num - 1)
		eat_sleep_think_loop(&all->philo, 1);
	else if (all->inf.philo_num - 1 != all->philo.num)
		eat_sleep_think_loop(&all->philo, 2);
	else
	{
		while (1)
		{
			thinking(&all->philo);
			eating(&all->philo);
			sleeping(&all->philo);
		}
	}
	return (NULL);
}

void	*even_philo_num(t_all *all)
{
	pthread_t *thread;

	thread = malloc(sizeof(pthread_t));
	sem_wait(all->sem.status);
	pthread_create(thread, NULL, spy_himself, all);
	if (all->philo.num % 2 == 0 || all->philo.num == 0)
		eat_sleep_think_loop(&all->philo, 1);
	else
		eat_sleep_think_loop(&all->philo, 2);
	return (NULL);
}

void	*spy_philo(t_all *all)
{
	int	i;
	pthread_t *death;

	i = 0;
	death = malloc (sizeof(pthread_t));
	pthread_create(death, NULL, check_death, all);
	while (1)
	{
		if (all->inf.times_eat > 0)
		{
			sem_wait(all->sem.meals);
			i++;
			if (i == all->inf.philo_num)
				return(philo_status(all, 0, 1));
		}
		else
			usleep(10);
	}
	return (NULL);
}

void	*start_philo(t_all *all)
{
	int	num;

	all->philo.start_timer = get_time();
	while(++all->num < all->inf.philo_num)
	{
		num = fork();
		all->pid[all->num] = num;
		if (num == 0 && all->inf.philo_num % 2 == 0)
		{
			all->philo.num = all->num + 1;
			even_philo_num(all);
			exit (0);
		}
		if (num == 0 && all->inf.philo_num % 2 != 0)
		{
			all->philo.num = all->num + 1;
			odd_philo_num(all);
			exit (0);
		}
	}
	usleep(10000);
	return (spy_philo(all));
}

int	main(int argc, char **argv)
{
	t_all		all;

	check_args(argc, argv, &all.inf);
	if (!init_semaphors(&all))
	{
		printf("ERROR DURING INITIALIZATION SEMAPHORS\n");
		return (0);
	}
	init_philo(&all);
	all.num = -1;
	all.pid = malloc(sizeof(pid_t) * all.inf.philo_num);
	if (!all.pid)
	{
		printf("ERROR DURING ALLOCATING MEMORY\n");
		return (0);
	}
	start_philo(&all);
	return (0);
}
