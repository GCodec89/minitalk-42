/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:29:32 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/16 11:13:00 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
			usleep(250);
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

	asp = 34;
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
