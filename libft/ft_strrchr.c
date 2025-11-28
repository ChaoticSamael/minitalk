/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:18:11 by elangari          #+#    #+#             */
/*   Updated: 2025/10/14 13:27:07 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	cnt;

	cnt = 0;
	str = (char *)s;
	while (*str != 0)
	{
		cnt++;
		str++;
	}
	while ((unsigned char)*str != (unsigned char)c && cnt != 0)
	{
		cnt--;
		str--;
	}
	if ((unsigned char)s[cnt] == (unsigned char)c)
		return (str);
	return (NULL);
}
