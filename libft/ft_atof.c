/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:02:28 by elangari          #+#    #+#             */
/*   Updated: 2025/10/14 13:30:24 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static float	ft_atof_dec(const char *nptr)
{
	float	atof_n;
	int		dec_cnt;

	atof_n = 0;
	dec_cnt = 0;
	while (*nptr >= 48 && *nptr <= 57)
	{
		if (dec_cnt > 6)
			return (0);
		atof_n = (*nptr - 48) + (atof_n * 10);
		nptr++;
		dec_cnt++;
	}
	atof_n = (atof_n * 10);
	atof_n = (atof_n * 10);
	atof_n = (atof_n * 10);
	while (dec_cnt > 0)
	{
		atof_n = atof_n / 10;
		dec_cnt--;
	}
	atof_n = atof_n / 10;
	atof_n = atof_n / 10;
	atof_n = atof_n / 10;
	return (atof_n);
}

float	ft_atof(const char *nptr)
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
	if (*nptr == '.')
	{
		nptr++;
		return ((atoi_n + ft_atof_dec(nptr)) * neg);
	}
	return (atoi_n * neg);
}
