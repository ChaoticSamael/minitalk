/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elangari <elagari@student.42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:39:23 by elangari          #+#    #+#             */
/*   Updated: 2025/10/14 20:09:26 by elangari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*aux;

	if (!lst || !f || !del)
		return (NULL);
	nlst = ft_lstnew(f(lst->content));
	aux = nlst;
	if (!nlst)
	{
		ft_lstclear(&aux, del);
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
		nlst->next = ft_lstnew(f(lst->content));
		nlst = nlst->next;
		if (!nlst)
		{
			ft_lstclear(&aux, del);
			return (NULL);
		}
	}
	return (aux);
}
