/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 21:36:30 by hballaba          #+#    #+#             */
/*   Updated: 2020/05/23 21:36:33 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*buffer;

	if (!new)
		return ;
	if (*lst)
	{
		buffer = *lst;
		while (buffer->next)
			buffer = buffer->next;
		buffer->next = new;
	}
	else
		*lst = new;
}
