/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:06:00 by elangari          #+#    #+#             */
/*   Updated: 2025/10/14 13:27:55 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str_aux;
	char	*str_m;
	size_t	cnt_s;
	size_t	cnt_m;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	cnt_m = 0;
	cnt_s = (size_t)start;
	if (ft_strlen(s) < start + len)
		str_m = ft_calloc(ft_strlen(s) - start + 1, sizeof(char));
	else
		str_m = ft_calloc(len + 1, 1);
	if (!str_m)
		return (NULL);
	str_aux = (char *)s;
	while (cnt_m < len && str_aux[cnt_s] != 0)
	{
		str_m[cnt_m] = str_aux[cnt_s];
		cnt_m++;
		cnt_s++;
	}
	return (str_m);
}
