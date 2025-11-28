/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:16:07 by elangari          #+#    #+#             */
/*   Updated: 2025/10/14 13:26:33 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str;
	char	*trg;
	size_t	str_i;
	size_t	trg_i;

	str_i = 0;
	str = (char *)big;
	trg = (char *)little;
	if (*trg == 0)
		return (str);
	while (str[str_i] != 0 && str_i + ft_strlen(little) <= len)
	{
		trg_i = 0;
		while (str[str_i + trg_i] == trg[trg_i] && trg[trg_i] != 0)
			trg_i++;
		if (trg[trg_i] == 0)
			return (str + str_i);
		str_i++;
	}
	return (NULL);
}
