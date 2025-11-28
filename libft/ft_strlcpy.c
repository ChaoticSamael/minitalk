/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:07:37 by elangari          #+#    #+#             */
/*   Updated: 2025/10/14 13:24:34 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	cnt;

	cnt = 0;
	if (dsize == 0)
		return (ft_strlen(src));
	while (src[cnt] != 0 && cnt < dsize - 1)
	{
		dst[cnt] = src[cnt];
		cnt++;
	}
	dst[cnt] = 0;
	return (ft_strlen(src));
}
