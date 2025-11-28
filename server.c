#include "minitalk.h"

void	sig_manager(int signal_received)
{
	static int	cnt;
	static int	size;
	static int	msg_cnt;
	static int	size_buff;
	static unsigned char mini_buff;
	char	*msg_buff;

	cnt++;
	if (size != 0)
	{
		mini_buff <<= 1;
		mini_buff |= (signal_received == SIGUSR1);
	}
	else
	{
		size_buff<<= 1;
		size_buff |= (signal_received == SIGUSR1);
	}
	if (cnt == 32 && size == 0)
	{
		size = size_buff;
		msg_buff = malloc(size * sizeof(char));
		cnt = 0;
	}
	if (cnt == 8 && mini_buff == 4)
	{
		msg_buff[msg_cnt] = 0;
		ft_printf("%s\n", msg_buff);
		free(msg_buff);
		size = 0;
		size_buff = 0;
		mini_buff = 0;
		cnt = 0;
		msg_cnt = 0;
	}
	else if (cnt == 8 && size != 0)
	{
		msg_buff[msg_cnt] = mini_buff;
		msg_cnt++;
		mini_buff = 0;
		cnt = 0;
	}
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
