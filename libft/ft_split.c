/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:02:39 by elangari          #+#    #+#             */
/*   Updated: 2025/10/14 13:22:24 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloc_creator(char const *s, char c)
{
	char	*str;
	size_t	cnt;
	char	**arr;

	cnt = 0;
	str = (char *)s;
	while (*str != 0)
	{
		if ((*(str + 1) == c || *(str + 1) == 0) && *str != c)
			cnt++;
		str++;
	}
	arr = malloc((cnt + 1) * sizeof(char *));
	return (arr);
}

static void	*ft_free_mallocs(char **arr, size_t cnt)
{
	while (cnt > 0)
	{
		free(arr[cnt]);
		cnt--;
	}
	free(arr[cnt]);
	free(arr);
	return ((NULL));
}

static char	**ft_real_split(char const *s, char c)
{
	char	**arr;
	size_t	a_i;
	size_t	s_i;
	size_t	ss_i;

	arr = ft_malloc_creator(s, c);
	a_i = 0;
	s_i = 0;
	ss_i = 0;
	while (arr && s[ss_i] != 0)
	{
		if (s[ss_i] == c && s[ss_i + 1] != c)
			s_i = ss_i + 1;
		if ((s[ss_i + 1] == c || s[ss_i + 1] == 0) && s[ss_i] != c)
		{
			arr[a_i] = ft_substr(s, s_i, ss_i - s_i + 1);
			if (!arr[a_i])
				return ((char **)ft_free_mallocs(arr, a_i));
			a_i++;
		}
		ss_i++;
	}
	if (arr)
		arr[a_i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	if (s == NULL)
		return (NULL);
	else
		return (ft_real_split(s, c));
}
