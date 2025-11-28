#include <unistd.h>

void	ft_putuns(unsigned nbr)
{
	char	c;

	if (nbr > 9)
	{
		ft_putuns(nbr / 10);
		c = nbr % 10 + 48;
		write(1, &c, 1);
	}
	else
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
}
