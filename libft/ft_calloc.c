/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:03:29 by elangari          #+#    #+#             */
/*   Updated: 2025/10/13 20:31:46 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void				*pnt;
	unsigned long long	total;

	total = size * nmemb;
	if (total > ULONG_MAX)
		return (NULL);
	pnt = malloc(total);
	if (!pnt)
		return (NULL);
	ft_bzero(pnt, size * nmemb);
	return (pnt);
}
