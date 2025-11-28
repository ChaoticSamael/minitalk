/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:05:50 by elangari          #+#    #+#             */
/*   Updated: 2025/10/15 23:08:23 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	cnt;
	char	*aux_src;
	char	*aux_dest;

	if (!dest && !src)
		return (NULL);
	aux_src = (char *)src;
	aux_dest = (char *)dest;
	cnt = 0;
	while (cnt < n)
	{
		aux_dest[cnt] = aux_src[cnt];
		cnt++;
	}
	return (aux_dest);
}
