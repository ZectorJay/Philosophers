/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 08:41:57 by hmickey           #+#    #+#             */
/*   Updated: 2021/05/15 17:17:30 by hmickey          ###   ########.fr       */
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

/*
**      @brief  counts lenght integer by its base
**
**      @param  num                     philosopher number
**      @param  timer           how many time left since programm start
**      @param  message         message to type
*/
void    type_message(int num, int timer, char *message)
{
        ft_putnbr(timer);
        write(1, " ", 1);
        ft_putnbr(num + 1);
        // if (message[4] == 'e')
        //         write(1, "\033[38;2;0;255;0m", 16);
		if (message[0] == 'd')
		{
				write (1, " ", 1);
                write(1, "\033[1;3;38;2;255;255;255m", 24);
		}
		write(1, message, ft_strlen(message));
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
