/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:29:39 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/13 14:33:12 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bit_to_char(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;

	(void)info;
	(void)context;
	if (sig == SIGUSR1)
	{
		i |= (0x01 << bit);
	}
	bit++;
	if (bit == 8)
	{
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
	sig.sa_flags = 0;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
}
