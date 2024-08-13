/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:35:28 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/13 22:13:43 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	*g_global;

void	ft_byte_to_str(int byte, siginfo_t *info)
{
	char	*c1;

	c1 = (char *)malloc(sizeof(char) * 2);
	if (!c1)
		return ;
	c1[0] = (char)byte;
	c1[1] = '\0';
	g_global = ft_strjoin_mod(g_global, c1);
	if (c1[0] == '\n')
	{
		ft_printf("%s", g_global);
		free(g_global);
		g_global = NULL;
		kill(info->si_pid, SIGUSR2);
	}
	free(c1);
}

void	ft_bit_to_byte(int sig, siginfo_t *info, void *context)
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
		ft_byte_to_str(i, info);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char *argv[])
{
	pid_t				pid;
	struct sigaction	sig;

	(void)argv;
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sig.sa_sigaction = ft_bit_to_byte;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
}
