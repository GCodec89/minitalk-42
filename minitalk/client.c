/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:29:32 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/10 11:45:20 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		usleep(100);
		bit++;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	pid_t	pid;
	char	*msg;

	i = 0;
	if (argc != 3)
		return (ft_printf("Error: Wrong Format!\n"));
	while (argv[1][i] != '\0')
	{
		if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
		{
			return (ft_printf("ERROR: PID invalid\n"));
		}
		i++;
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	while (*msg != '\0')
	{
		send_bits(pid, *msg);
		msg++;
	}
	send_bits(pid, '\n');
}
