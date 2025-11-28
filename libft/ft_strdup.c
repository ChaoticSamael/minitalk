/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:07:10 by elangari          #+#    #+#             */
/*   Updated: 2025/10/14 13:23:24 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	cnt;
	char	*str;

	cnt = 0;
	while (s[cnt] != 0)
		cnt++;
	str = malloc(cnt + 1);
	if (!str)
		return (NULL);
	cnt = 0;
	while (s[cnt] != 0)
	{
		str[cnt] = s[cnt];
		cnt++;
	}
	str[cnt] = 0;
	return (str);
}
