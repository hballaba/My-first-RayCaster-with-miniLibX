/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 22:53:49 by hballaba          #+#    #+#             */
/*   Updated: 2020/05/15 22:53:54 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char *dest;

	dest = (char*)str;
	while (*dest && *dest != ch)
		dest++;
	if (*dest == ch)
		return (dest);
	else
		return (NULL);
}
