/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 10:35:49 by elangari          #+#    #+#             */
/*   Updated: 2025/10/14 13:27:31 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	front;
	size_t	back;

	if (!s1)
		return (NULL);
	front = 0;
	back = ft_strlen(s1);
	while (ft_strchr(set, s1[front]) && s1[front] != 0)
		front++;
	while (ft_strchr(set, s1[back]) && back > 0)
		back--;
	if (back < front)
		return (ft_calloc(1, sizeof(char)));
	s2 = ft_substr(s1, front, back - front + 1);
	return (s2);
}
