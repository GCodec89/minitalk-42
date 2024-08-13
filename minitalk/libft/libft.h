/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:58:50 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/13 17:29:36 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "printf/ft_printf.h"

int		ft_atoi(char *str);
char	*ft_strjoin_mod(char *s1, char *s2);
size_t	ft_strlen(const char *s);

#endif