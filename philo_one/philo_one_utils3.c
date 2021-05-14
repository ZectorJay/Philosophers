/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 08:41:57 by hmickey           #+#    #+#             */
/*   Updated: 2021/05/14 10:33:48 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*detach_and_destroy(pthread_t *thread_num, t_all *all)
{
	all->num = -1;
	while (++all->num < all->inf.philo_num)
	{
		pthread_detach(thread_num[all->num]);
		pthread_mutex_destroy(&all->philo[all->num].left);
	}
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
	ft_putnbr(num);
	ft_putstr(message);
}
