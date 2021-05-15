/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:06:36 by hmickey           #+#    #+#             */
/*   Updated: 2021/05/15 13:05:11 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	*init_variables(t_all *all, int *k)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * all->inf.philo_num + 2);
	if (!array)
		return (NULL);
	i = -1;
	*k = -1;
	while (++i < all->inf.philo_num + 2)
		array[i] = -1;
	return (array);
}

void	eat_sleep_think_loop(t_philo *philo, int flag)
{
	if (flag == 1)
	{
		while (1)
		{
			eating(philo);
			sleeping(philo);
			thinking(philo);
		}
	}
	if (flag == 2)
	{
		while (1)
		{
			sleeping(philo);
			thinking(philo);
			eating(philo);
		}
	}
}

void	eating(t_philo *philo)
{
	sem_wait(philo->sem->forks);
	philo->previous_meal = philo->current_meal;
	sem_wait(philo->sem->output);
	type_message(philo->num, get_time() - philo->start_timer,
		" has taken a fork\n");
	sem_post(philo->sem->output);
	my_usleep(philo->eating_timer);
	sem_post(philo->sem->forks);
	philo->current_meal = get_time() - philo->start_timer;
	sem_wait(philo->sem->output);
	type_message(philo->num, get_time() - philo->start_timer,
		" is eating\n");
	philo->times_eat += 1;
	sem_post(philo->sem->output);
}

void	sleeping(t_philo *philo)
{
	sem_wait(philo->sem->output);
	type_message(philo->num, get_time() - philo->start_timer,
		" is sleeping\n");
	sem_post(philo->sem->output);
	my_usleep(philo->sleeping_timer);
}

void	thinking(t_philo *philo)
{
	sem_wait(philo->sem->output);
	type_message(philo->num, get_time() - philo->start_timer,
		" is thinking\n");
	sem_post(philo->sem->output);
}
