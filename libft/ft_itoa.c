/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:41:46 by elangari          #+#    #+#             */
/*   Updated: 2025/10/14 13:32:55 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_cnt(long n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	m;
	int		i;

	m = (long)n;
	i = 0;
	if (m < 0)
	{
		m = m * (-1);
		i++;
	}
	str = ft_calloc(ft_cnt(m) + 1 + i, 1);
	if (!str)
		return (NULL);
	i = i + (ft_cnt(m) - 1);
	str[0] = 45;
	while (m > 9)
	{
		str[i] = m % 10 + 48;
		m = m / 10;
		i--;
	}
	str[i] = m % 10 + 48;
	return (str);
}
