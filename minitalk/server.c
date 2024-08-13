/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:29:39 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/13 20:55:55 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_global;

void	ft_bit_to_char(int sig)
{
	static int	bit;
	static int	i;
	char		*c1;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		c1 = (char *)malloc(sizeof(char) * 2);
		if (!c1)
			return ;
		c1[0] = (char)i;
		c1[1] = '\0';
		g_global = ft_strjoin_mod(g_global, c1);
		if (c1[0] == '\n')
		{
			ft_printf("%s", g_global);
			free(g_global);
			g_global = NULL;
		}
		bit = 0;
		i = 0;
		free(c1);
	}
}

int	main(int argc, char *argv[])
{
	pid_t				pid;

	(void)argv;
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_bit_to_char);
		signal(SIGUSR2, ft_bit_to_char);
		pause();
	}
}
