/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:27:46 by elangari          #+#    #+#             */
/*   Updated: 2025/10/13 20:28:49 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	aux = *lst;
	while (*lst != NULL)
	{
		aux = aux->next;
		del((*lst)->content);
		free(*lst);
		*lst = aux;
	}
}
