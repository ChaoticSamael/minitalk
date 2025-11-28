/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:06:05 by elangari          #+#    #+#             */
/*   Updated: 2025/10/14 13:36:18 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			cnt;

	cnt = 1;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (cnt <= n)
	{
		if (*str1 == *str2)
		{
			if (cnt == n)
				return (0);
			else
			{
				cnt++;
				str1++;
				str2++;
			}
		}
		else
			return (*str1 - *str2);
	}
	return (0);
}
