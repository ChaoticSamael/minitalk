/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:06:39 by elangari          #+#    #+#             */
/*   Updated: 2025/10/14 13:19:18 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	cnt;
	char	*s_aux;

	cnt = 1;
	s_aux = s;
	while (cnt <= n)
	{
		*s_aux = c;
		s_aux++;
		cnt++;
	}
	return (s);
}
