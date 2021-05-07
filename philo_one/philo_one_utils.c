/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 07:14:16 by hmickey           #+#    #+#             */
/*   Updated: 2021/05/07 07:22:47 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static long int		check_num(const char *str, int i)
{
	long int a;

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

int					ft_atoi(const char *str)
{
	int			i;
	int			m;

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