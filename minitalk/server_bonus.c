/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:35:28 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/14 15:51:00 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	*ft_joinchar(char *str, char c, siginfo_t *info)
{
	char	*newstr;
	int		i;
	int		len;

	if (!str)
	{
		kill(info->si_pid, SIGUSR2);
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	len = ft_strlen(str);
	newstr = (char *)malloc(sizeof(char) * (len + 2));
	if (!newstr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i++] = c;
	newstr[i] = '\0';
	free(str);
	return (newstr);
}

void	ft_bit_to_char(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	cchar;
	static char	*str;

	(void)context;
	if (sig == SIGUSR1)
		cchar |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (cchar == '\0')
		{
			ft_printf("%s", str);
			ft_printf("\n");
			free(str);
			str = NULL;
		}
		else
		{
			str = ft_joinchar(str, cchar, info);
		}
		bit = 0;
		cchar = 0;
	}
}

int	main(int argc, char *argv[])
{
	pid_t				pid;
	struct sigaction	sig;

	(void)argv;
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
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
