/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:52:37 by hmickey           #+#    #+#             */
/*   Updated: 2021/05/14 18:45:25 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*philo_status(t_all *all, int num, int **array, int flag)
{
	sem_wait(all->sem.output);
	all->num = -2;
	if (flag == 1)
		printf("ALL PHILOSOPHERS ARE FULL");
	else
		type_message(num, get_time() - all->start, " died\n");
	free(*array);
	return (NULL);
}

static long int	check_num(const char *str, int i)
{
	long int	a;

	a = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		a = a + (str[i] - 48);
		i++;
		if (str[i] >= 48 && str[i] <= 57)
			a = a * 10;
		else if (str[i] != '\0')
			return (0);
	}
	return (a);
}

long int	ft_atoi(const char *str)
{
	int	i;
	int	m;

	m = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (m == 1 && check_num(str, i) < 0)
		return (-1);
	if (m == -1 && check_num(str, i) < 0)
		return (0);
	return (m * check_num(str, i));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr(long int n)
{
	long	a;
	int		k;

	a = n;
	k = 0;
	if (a < 0)
	{
		write(1, "-", 1);
		a *= -1;
	}
	if (a >= 10)
	{
		ft_putnbr(a / 10);
		k = a % 10 + 48;
		write(1, &k, 1);
	}
	else
	{
		k = a % 10 + 48;
		write(1, &k, 1);
	}
}
