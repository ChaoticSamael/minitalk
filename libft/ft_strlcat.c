/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:55:07 by elangari          #+#    #+#             */
/*   Updated: 2025/10/14 13:24:15 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	cnt;
	size_t	n;
	size_t	size;

	size = ft_strlen(dst);
	cnt = 0;
	n = 0;
	while (dst[n] != 0 && n + 1 < dsize)
		n++;
	while (src[cnt] != 0 && n + 1 < dsize)
	{
		dst[n] = src[cnt];
		cnt++;
		n++;
	}
	if (n >= size && n < dsize)
		dst[n] = 0;
	if (dsize < size)
		return (ft_strlen(src) + dsize);
	return (ft_strlen(src) + size);
}
