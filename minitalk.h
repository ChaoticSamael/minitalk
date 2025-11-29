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
