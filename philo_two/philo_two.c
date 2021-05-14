/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:55:24 by hmickey           #+#    #+#             */
/*   Updated: 2021/05/14 19:23:31 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	*odd_philo_num(void *get_info)
{
	t_philo	*philo;

	philo = (t_philo *) get_info;
	if (philo->num % 2 == 0 && philo->num != philo->info->philo_num - 1)
	{
		eat_sleep_think_loop(philo, 1);
	}
	else if (philo->info->philo_num - 1 != philo->num)
	{
		eat_sleep_think_loop(philo, 2);
	}
	else
	{
		while (1)
		{
			thinking(philo);
			eating(philo);
			sleeping(philo);
		}
	}
	return (NULL);
}

void	*even_philo_num(void *get_info)
{
	t_philo	*philo;

	philo = (t_philo *)get_info;
	if (philo->num % 2 == 0 || philo->num == 0)
		eat_sleep_think_loop(philo, 1);
	else
		eat_sleep_think_loop(philo, 2);
	return (NULL);
}

void	*spy_philo(void *get_info)
{
	int			i;
	t_all	 	*all;
	int			*check;
	int			k;

	all = (t_all *)get_info;
	check = init_variables(all, &k);
	while (1)
	{
		i = -1;
		while (++i < all->inf.philo_num)
		{
			if (all->philo[i].times_eat >= all->inf.times_eat
				&& !intchr(check, i))
				check[++k] = i;
			if (k >= all->inf.philo_num - 1 && all->inf.times_eat != -1)
				return (philo_status(all, 0, &check, 1));
			all->philo[i].death_timer = get_time() - all->start
				- all->philo[i].current_meal;
			if (all->philo[i].death_timer > all->inf.life_time)
				return (philo_status(all, i, &check, 2));
		}
	}
	return (NULL);
}

void	*start_philo(pthread_t *thread_num, t_all *all)
{
	all->start = get_time();
	while (++all->num <= all->inf.philo_num)
	{
		all->philo[all->num].start_timer = all->start;
		if (all->inf.philo_num % 2 == 0 && all->num != all->inf.philo_num)
			pthread_create(&thread_num[all->num], NULL, even_philo_num,
				&all->philo[all->num]);
		else if (all->inf.philo_num % 2 != 0 && all->num != all->inf.philo_num)
			pthread_create(&thread_num[all->num], NULL, odd_philo_num,
				&all->philo[all->num]);
		if (all->num == all->inf.philo_num)
			pthread_create(&thread_num[all->num], NULL, spy_philo, all);
	}
	while (1)
	{
		if (all->num == -2)
		{
			return (NULL);
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	*thread_num;
	t_all		all;

	check_args(argc, argv, &all.inf);
	thread_num = malloc(sizeof(pthread_t *) * all.inf.philo_num + 1);
	all.philo = malloc(sizeof(t_philo *) * all.inf.philo_num + 1);
	if (!thread_num || !all.philo)
		printf("Error during allocating memory\n");
	else
	{
		init_semaphors(&all);
		init_philo(&all);
		all.num = -1;
		start_philo(thread_num, &all);
		detach_and_destroy(thread_num, &all);
		free(thread_num);
		free(all.philo);
	}
	return (0);
}
