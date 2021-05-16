/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 08:41:57 by hmickey           #+#    #+#             */
/*   Updated: 2021/05/14 19:30:53 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*detach_and_destroy(pthread_t *thread_num, t_all *all)
{
	(void)thread_num;
	(void)all;
	return (NULL);
}

void	*check_death(void *get_info)
{
	t_all *all;
	int	i;

	i = -1;
	all = (t_all *)get_info;
	sem_wait(all->sem.status);
	while (all->pid[++i])
		kill(all->pid[i], SIGTERM);
	exit (0);
}

void	type_message(int num, int timer, char *message)
{
	ft_putnbr(timer);
	write(1, " ", 1);
	ft_putnbr(num);
	ft_putstr(message);
}

void	*spy_himself(void *get_info)
{
	t_all *all;

	all = (t_all *)get_info;
	if (all->inf.times_eat > 0)
		sem_wait(all->sem.meals);
	while (1)
	{
		all->philo.death_timer = get_time() - all->philo.start_timer - all->philo.current_meal;
		if (all->philo.death_timer > all->inf.life_time)
			return (philo_status(all, all->philo.num, 2));
		if (all->inf.times_eat > 0
			&& all->philo.times_eat == all->inf.times_eat)
			sem_post(all->sem.meals);
		usleep(10);
	}
	return (NULL);
}

int	init_semaphors(t_all *all)
{
	sem_unlink("/semaphor");
	all->sem.output = sem_open("/semaphor", O_CREAT | O_EXCL, 0755, 1);
	sem_unlink("/forks");
	all->sem.forks = sem_open("/forks", O_CREAT | O_EXCL, 0755,
			all->inf.philo_num / 2);
	sem_unlink("/status");
	printf("PHILO-NUM %d\n", all->inf.philo_num);
	all->sem.status = sem_open("/status", O_CREAT | O_EXCL, 0755,
			all->inf.philo_num);
	if (all->inf.times_eat > 0)
	{
		sem_unlink("/meals");
		all->sem.meals = sem_open("/meals", O_CREAT | O_EXCL, 0755, all->inf.times_eat);
		if (all->sem.meals == SEM_FAILED)
			return (0);
	}
	if (all->sem.output == SEM_FAILED || all->sem.status == SEM_FAILED
		|| all->sem.forks == SEM_FAILED)
		return (0);
	return (1);
}
