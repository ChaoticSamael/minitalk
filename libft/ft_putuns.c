/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:30:12 by elangari          #+#    #+#             */
/*   Updated: 2025/11/29 20:30:14 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putuns(unsigned int nbr)
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
