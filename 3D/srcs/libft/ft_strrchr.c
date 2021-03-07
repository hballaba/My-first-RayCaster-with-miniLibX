/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 22:55:40 by hballaba          #+#    #+#             */
/*   Updated: 2020/05/15 22:55:43 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = (char*)str;
	while (*dest)
	{
		dest++;
		i++;
	}
	if ((char)ch == '\0')
		return (dest);
	while (i > 0 && *dest != ch)
	{
		dest--;
		i--;
		if (*dest == ch)
			return (dest);
	}
	return (0);
}
