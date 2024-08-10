/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:29:39 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/10 10:31:54 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_listen(int sig)
{
	static int	bit;
	static int	i;

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
	pid_t	pid;
	int		asp;

	(void)argv;
	pid = getpid();
	asp = 34;
	ft_printf("Server PID: ");
	write (1, &asp, 1);
	ft_printf("%d", pid);
	write (1, &asp, 1);
	write (1, "\n", 1);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_listen);
		signal(SIGUSR2, ft_listen);
		pause();
	}
}
