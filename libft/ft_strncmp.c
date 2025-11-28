/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:08:03 by elangari          #+#    #+#             */
/*   Updated: 2025/10/14 13:26:10 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < n)
	{
		if (s1[cnt] == s2[cnt])
		{
			if (s1[cnt] == 0 && s2[cnt] == 0)
				return (0);
			else
				cnt++;
		}
		else
			return ((unsigned char)s1[cnt] - (unsigned char)s2[cnt]);
	}
	return (0);
}
