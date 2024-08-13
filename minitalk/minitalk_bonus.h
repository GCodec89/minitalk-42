/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:11:06 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/13 21:22:37 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <aio.h>
# include "libft/libft.h"

void	send_bits(pid_t pid, char c);
void	ft_bit_to_byte(int sig, siginfo_t *info, void *context);
void	ft_byte_to_str(int byte, siginfo_t *info);

#endif