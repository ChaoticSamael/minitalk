/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:30:31 by elangari          #+#    #+#             */
/*   Updated: 2025/11/29 20:30:32 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

void	ft_putnbr_long_base(unsigned long nbr, char *d)
{
	char	c;

	if (nbr > (ft_strlen(d) - 1))
	{
		ft_putnbr_long_base(nbr / ft_strlen(d), d);
		c = *(d + nbr % ft_strlen(d));
		write(1, &c, 1);
	}
	else
	{
		c = *(d + nbr);
		write(1, &c, 1);
	}
}
