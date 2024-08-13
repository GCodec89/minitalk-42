/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:35:28 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/13 14:54:04 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_bit_to_char(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;

	(void)context;
	if (sig == SIGUSR1)
	{
		i |= (0x01 << bit);
	}
	bit++;
	if (bit == 8)
	{
		if (i == '\0')
		{
			kill(info->si_pid, SIGUSR2);
		}
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char *argv[])
{
	pid_t				pid;
	char				asp;
	struct sigaction	sig;

	(void)argv;
	pid = getpid();
	asp = 34;
	ft_printf("Server PID: %c%d%c\n", asp, pid, asp);
	sig.sa_sigaction = ft_bit_to_char;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
}
