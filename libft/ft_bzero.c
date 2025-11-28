/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:02:51 by elangari          #+#    #+#             */
/*   Updated: 2025/10/14 13:30:45 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	cnt;
	char	*s_aux;

	cnt = 1;
	s_aux = s;
	while (cnt <= n)
	{
		*s_aux = '\0';
		s_aux++;
		cnt++;
	}
}
