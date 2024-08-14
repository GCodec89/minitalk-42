/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:35:16 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/14 14:41:59 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	final_msg(int signum)
{
	if (signum == SIGUSR2)
		ft_printf("Message received by the server succesfully!\n");
}

void	send_bits(pid_t pid, char *str)
{
	int		bit;
	size_t	i;

	i = 0;
	while (i <= ft_strlen(str))
	{
		bit = 0;
		while (bit < 8)
		{
			if ((str[i] & (0x01 << bit)) != 0)
			{
				kill(pid, SIGUSR1);
			}
			else
			{
				kill(pid, SIGUSR2);
			}
			usleep(200);
			bit++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t				pid;
	char				*msg;
	char				asp;
	struct sigaction	sig;

	asp = 34;
	sig.sa_handler = &final_msg;
	sig.sa_flags = 0;
	sigaction(SIGUSR2, &sig, NULL);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		msg = argv[2];
		send_bits(pid, msg);
	}
	else
	{
		ft_printf("Error: wrong format\n");
		ft_printf("Try: ./client %cPID%c %cMESSAGE%c\n", asp, asp, asp, asp);
	}
}

