/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:06:36 by hmickey           #+#    #+#             */
/*   Updated: 2021/05/16 15:59:45 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
	sem_wait(philo->sem->output);
	type_message(philo->num, get_time() - philo->start_timer,
		" has taken a fork\n");
	type_message(philo->num, get_time() - philo->start_timer,
		" has taken a fork\n");
	philo->current_meal = get_time() - philo->start_timer;
	type_message(philo->num, get_time() - philo->start_timer,
		" is eating\n");
	sem_post(philo->sem->output);
	my_usleep(philo->eating_timer);
	philo->times_eat += 1;
	if(philo->info->times_eat > 0)
		sem_post(philo->sem->meals);
	sem_post(philo->sem->forks);
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
