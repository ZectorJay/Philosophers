/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:16:01 by hmickey           #+#    #+#             */
/*   Updated: 2021/05/15 12:55:25 by hmickey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"


int main()
{
	int forking;
	pid_t pid;
	int i = 5;
	int g_num;
	g_num = 0;
	int	num;

	while (i--)
	{
		forking = fork();
		g_num++;
		if (forking == 0)
		{
			num = g_num;
			break ;
		}
	}
	if(forking)
	{
		pid = getpid();
		printf("process ID = %d\n", pid); // ID РОДИТЕЛЬ
	}
	else
	{
		printf("PIDARAS %d\n", num);
	}
	while (1)
	{}
}