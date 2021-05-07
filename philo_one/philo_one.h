/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 07:14:28 by hmickey           #+#    #+#             */
/*   Updated: 2021/05/07 11:50:34 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

struct timeval	g_start;

typedef struct s_info
{
	int			life_time;
	int			times_eat;
	int			eating_timer;
	int			sleeping_timer;
	int			philo_num;
	int			num;
}				t_info;

typedef	struct s_philo
{
	int			num;
	int			death_timer;
	int			status;		//1 - eating, 2 - sleeping, 3 - thinking
}				t_philo;

typedef struct s_all
{
	t_philo		*philo;
	t_info		info;
	int			num;
}				t_all;


int			ft_atoi(const char *str);
long int	check_time(void);
#endif