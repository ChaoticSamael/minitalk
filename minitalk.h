#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"

//server
int		ft_isnum(char *s);
void	turn_n_send(int pid, unsigned char c);

//client
void	sig_manager(int signal_received);

#endif
