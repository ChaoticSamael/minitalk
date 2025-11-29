#include <unistd.h>
#include <stdio.h>
#include "libft.h"

void	ft_putnbr_base(unsigned int nbr, char *d)
{
	char	c;

	if (nbr > (ft_strlen(d) - 1))
	{
		ft_putnbr_base(nbr / ft_strlen(d), d);
		c = *(d + nbr % ft_strlen(d));
		write(1, &c, 1);
	}
	else
	{
		c = *(d + nbr);
		write(1, &c, 1);
	}
}
