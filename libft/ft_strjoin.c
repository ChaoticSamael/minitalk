/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:07:25 by elangari          #+#    #+#             */
/*   Updated: 2025/10/08 09:19:47 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[cnt] != 0)
	{
		str[cnt] = s1[cnt];
		cnt++;
	}
	while (s2[i] != 0)
	{
		str[cnt] = s2[i];
		cnt++;
		i++;
	}
	str[cnt] = 0;
	return (str);
}
