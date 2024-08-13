/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:33:22 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/13 13:12:27 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <aio.h>
# include "libft/libft.h"

void	ft_bit_to_char(int sig, siginfo_t *info, void *context);
void	send_bits(pid_t pid, char c);

#endif