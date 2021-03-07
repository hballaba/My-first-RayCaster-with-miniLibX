/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 22:53:21 by hballaba          #+#    #+#             */
/*   Updated: 2020/05/23 22:53:26 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *clean;
	t_list *buffer;

	clean = *lst;
	while (clean)
	{
		buffer = clean->next;
		ft_lstdelone(clean, del);
		clean = buffer;
	}
	*lst = NULL;
}
