/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:30:46 by elangari          #+#    #+#             */
/*   Updated: 2025/11/29 20:30:48 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_sig
{
	int				cnt;
	int				size;
	int				msg_cnt;
	int				size_buff;
	unsigned char	mini_buff;
	char			*msg_buff;
}					t_sig;

//server
int		ft_isnum(char *s);
void	turn_n_send(int pid, unsigned char c);

//client
void	sig_manager(int signal_received);

#endif
