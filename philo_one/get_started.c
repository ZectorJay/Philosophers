/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_started.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:50:05 by hmickey           #+#    #+#             */
/*   Updated: 2021/05/07 07:47:56 by hmickey          ###   ########.fr       */
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

void	*start_philo_life(void *pizda)
{
	printf("Philo №%d has started his life\n", (int)pizda);
	usleep(100);
	printf("Philo №%d died\n", (int)pizda);
	return NULL;
}

void	start_philo(pthread_t *philo, int phil_num, char **argv)
{
	struct timeval current_time;
	long int timing;
	void *k;

	gettimeofday(&current_time, 0);
	timing = current_time.tv_usec;
	printf("TIME = %ld\n", current_time.tv_usec - timing);
	k = 0;
	while ((int)k < phil_num)
	{
		pthread_create(&philo[(int)k], NULL, start_philo_life, k);
		k++;
	}
	k = 0;
	while ((int)k < phil_num)
	{
		pthread_join(philo[(int)k], NULL);
		k++;
	}
	gettimeofday(&current_time, 0);
	printf("TIME = %ld\n", current_time.tv_usec - timing);
	pthread_mutex_destroy(&left);
	pthread_mutex_destroy(&right);
}

int main(int argc, char **argv)
{
	pthread_t	*philo;				// Можно будет вынести в функцию старт_фило

	int	phil_num;
	if (argc != 5 && argc != 6)
	{
		printf("Dude, not enough args. Fix it.\n");
		exit (0);
	}
	phil_num = ft_atoi(argv[1]);
	if (phil_num <= 0)
	{
		printf("Dude, you type something weird in args. Check and fix it.");
		exit (0);
	}
	pthread_mutex_init(&left, NULL);
	pthread_mutex_init(&right, NULL);
	philo = malloc(phil_num);
	if (!philo)
		printf("error during allocating memory\n");
	else
	{
		start_philo(philo, phil_num, argv);
		free(philo);
	}
	exit (0);
}