/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 21:03:44 by hballaba          #+#    #+#             */
/*   Updated: 2020/05/25 21:03:50 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list_res;
	t_list	*new_elem;

	if (!f || !del || !lst)
		return (NULL);
	new_list_res = NULL;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			ft_lstdelone(new_elem, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list_res, new_elem);
		lst = lst->next;
	}
	return (new_list_res);
}
