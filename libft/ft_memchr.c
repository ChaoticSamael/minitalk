/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:05:28 by elangari          #+#    #+#             */
/*   Updated: 2025/10/14 13:35:24 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			cnt;
	unsigned char	*str;

	if (n == 0)
		return (NULL);
	str = (unsigned char *)s;
	cnt = 1;
	while ((unsigned char)*str != (unsigned char)c && cnt < n)
	{
		str++;
		cnt++;
	}
	if ((unsigned char)*str == (unsigned char)c)
		return (str);
	return (NULL);
}
