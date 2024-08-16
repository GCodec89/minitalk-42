/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:29:39 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/16 14:43:12 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_joinchar(char *str, char c)
{
	char	*newstr;
	int		i;
	int		len;

	if (!str)
	{
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
	(void)info;
	if (sig == SIGUSR1)
		cchar |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (cchar == '\0')
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
		}
		else
		{
			str = ft_joinchar(str, cchar);
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
	sig.sa_flags = 0;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
}
