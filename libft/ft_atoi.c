/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:02:28 by elangari          #+#    #+#             */
/*   Updated: 2025/10/14 13:30:24 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	atoi_n;

	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	neg = 1;
	if (*nptr == 45)
	{
		neg = -1;
		nptr++;
	}
	else if (*nptr == 43)
		nptr++;
	atoi_n = 0;
	while (*nptr >= 48 && *nptr <= 57)
	{
		atoi_n = (*nptr - 48) + (atoi_n * 10);
		nptr++;
	}
	return (atoi_n * neg);
}
