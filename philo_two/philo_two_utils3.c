/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 08:41:57 by hmickey           #+#    #+#             */
/*   Updated: 2021/05/14 19:30:53 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	*detach_and_destroy(pthread_t *thread_num, t_all *all)
{
	all->num = -1;
	while (++all->num < all->inf.philo_num)
		pthread_detach(thread_num[all->num]);
	all->num = -1;
	while (++all->num <= all->inf.philo_num)
		pthread_join(thread_num[all->num], NULL);
	sem_close(all->sem.forks);
	sem_close(all->sem.meals);
	sem_close(all->sem.output);
	sem_unlink("/semaphor");
	sem_unlink("/forks");
	sem_unlink("/meals");
	return (NULL);
}

int	intchr(int *row, int find)
{
	int	i;

	i = -1;
	while (row[++i] != -1)
		if (row[i] == find)
			return (1);
	return (0);
}

void	type_message(int num, int timer, char *message)
{
	ft_putnbr(timer);
	write(1, " ", 1);
	ft_putnbr(num + 1);
	ft_putstr(message);
}

int	init_semaphors(t_all *all)
{
	sem_unlink("/semaphor");
	all->sem.output = sem_open("/semaphor", O_CREAT | O_EXCL, 0755, 1);
	sem_unlink("/forks");
	all->sem.forks = sem_open("/forks", O_CREAT | O_EXCL, 0755,
			all->inf.philo_num / 2);
	sem_unlink("/meals");
	all->sem.meals = sem_open("/meals", O_CREAT | O_EXCL, 0755, 1);
	if (all->sem.output == SEM_FAILED
		|| all->sem.forks == SEM_FAILED || all->sem.meals == SEM_FAILED)
		return (0);
	return (1);
}
