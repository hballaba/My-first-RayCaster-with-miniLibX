/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 16:30:33 by hballaba          #+#    #+#             */
/*   Updated: 2020/05/24 12:10:08 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*bbuf;
	char	*lbuf;
	size_t	i;
	size_t	l;

	if (!*little)
		return ((char*)big);
	bbuf = (char*)big;
	lbuf = (char*)little;
	while (*bbuf && len > 0)
	{
		i = 0;
		l = len;
		while (lbuf[i] == bbuf[i] && l >= i)
		{
			i++;
			if (!lbuf[i] && ft_memcmp(bbuf, lbuf, i) == 0)
				return (bbuf);
		}
		bbuf++;
		len--;
	}
	return (NULL);
}
