/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 22:52:08 by hballaba          #+#    #+#             */
/*   Updated: 2020/05/15 22:52:13 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*buf;
	unsigned char	*dst;
	size_t			i;

	i = 0;
	buf = (unsigned char*)src;
	dst = (unsigned char*)dest;
	while (n > 0)
	{
		dst[i] = buf[i];
		if (dst[i] == (unsigned char)c)
		{
			dest = dst;
			return (dest + i + 1);
		}
		n--;
		i++;
	}
	return (0);
}
