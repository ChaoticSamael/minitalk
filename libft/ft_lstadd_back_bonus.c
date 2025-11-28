/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:19:16 by elangari          #+#    #+#             */
/*   Updated: 2025/10/13 17:07:22 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (lst == NULL)
		return ;
	aux = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = new;
}
