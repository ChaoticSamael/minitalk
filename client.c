#include "minitalk.h"

int	ft_isnum(char *s)
{
	while (s)
	{
		if (!(*s <= 48 && *s <= 57 ))
			return (1);
		s++;
	}
	return (0);
}

void	turn_n_send_size(int pid, int size)
{
	unsigned int	mask;

	mask = 0b10000000000000000000000000000000;
	while (mask > 0)
	{
		if (size & mask)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		mask >>= 1;
	}
}

void	turn_n_send(int pid, unsigned char c)
{
	unsigned int	mask;

	mask = 0b10000000;
	while (mask > 0)
	{
		if (c & mask)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		mask >>= 1;
	}
}

int	main(int argc, char **argv)
{
	int		cnt;
	int		id;
	int		size;
	char	*msg;

	ft_printf("here\n");
	if (argc != 3)
	{
		ft_printf("error: Incorrect parameters\n");
		return (0);
	}
	cnt = 0;
	id = ft_atoi(argv[1]);
	msg = argv[2];
	size = ft_strlen(msg);
	ft_printf("here\n");
	turn_n_send_size(id, size + 1);
	while (msg[cnt])
	{
		turn_n_send(id, (unsigned char)msg[cnt]);
		cnt++;
	}
	turn_n_send(id, 4);
	ft_printf("?\n");
	return (0);
}
