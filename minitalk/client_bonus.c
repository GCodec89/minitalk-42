/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:35:16 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/13 22:12:21 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	final_msg(int signum)
{
	if (signum == SIGUSR2)
		ft_printf("Message received by the server succesfully!\n");
}

void	send_bits(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(500);
		bit++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t				pid;
	char				*msg;
	char				asp;

	asp = 34;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		msg = argv[2];
		signal(SIGUSR2, final_msg);
		while (*msg != '\0')
		{
			send_bits(pid, *msg);
			msg++;
		}
		send_bits(pid, '\n');
	}
	else
	{
		ft_printf("Error: wrong format, try:\n");
		ft_printf("./client_bonus %cPID%c %cMESSAGE%c\n", asp, asp, asp, asp);
	}
}
