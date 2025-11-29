/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:29:23 by elangari          #+#    #+#             */
/*   Updated: 2025/11/29 20:29:25 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_msg(t_sig *sig)
{
	sig->msg_buff[sig->msg_cnt] = 0;
	ft_printf("%s\n", sig->msg_buff);
	free(sig->msg_buff);
	sig->size = 0;
	sig->size_buff = 0;
	sig->mini_buff = 0;
	sig->cnt = 0;
	sig->msg_cnt = 0;
}

void	save_msg(t_sig *sig)
{
	sig->msg_buff[sig->msg_cnt] = sig->mini_buff;
	sig->msg_cnt++;
	sig->mini_buff = 0;
	sig->cnt = 0;
}

void	sig_manager(int signal_received)
{
	static t_sig	sig;

	sig.cnt++;
	if (sig.size != 0)
	{
		sig.mini_buff <<= 1;
		sig.mini_buff |= (signal_received == SIGUSR1);
	}
	else
	{
		sig.size_buff <<= 1;
		sig.size_buff |= (signal_received == SIGUSR1);
	}
	if (sig.cnt == 32 && sig.size == 0)
	{
		sig.size = sig.size_buff;
		sig.msg_buff = malloc(sig.size * sizeof(char));
		sig.cnt = 0;
	}
	if (sig.cnt == 8 && sig.mini_buff == 4)
		print_msg(&sig);
	else if (sig.cnt == 8 && sig.size != 0)
		save_msg(&sig);
}

int	main(void)
{
	printf("server pid=%d\n", getpid());
	signal(SIGUSR2, sig_manager);
	signal(SIGUSR1, sig_manager);
	while (42)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
