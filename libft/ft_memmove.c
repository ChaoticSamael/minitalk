/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:12:45 by elangari          #+#    #+#             */
/*   Updated: 2025/10/15 23:07:31 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*a_dest;
	size_t	cnt;

	if (!dest && !src)
		return (NULL);
	a_dest = (char *)dest;
	cnt = 0;
	if (src < dest)
	{
		while (n > 0)
		{
			a_dest[n - 1] = ((char *)src)[n - 1];
			n--;
		}
	}
	else
	{
		while (cnt < n)
		{
			a_dest[cnt] = ((char *)src)[cnt];
			cnt++;
		}
	}
	return (a_dest);
}
