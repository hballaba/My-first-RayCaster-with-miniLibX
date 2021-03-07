/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 22:53:03 by hballaba          #+#    #+#             */
/*   Updated: 2020/05/15 22:53:08 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*buf;
	char	*dst;
	size_t	i;

	if (!src && !dest)
		return (dest);
	dst = (char*)dest;
	buf = (char*)src;
	i = 0;
	while (n > 0)
	{
		dst[i] = buf[i];
		n--;
		i++;
	}
	dest = dst;
	return (dest);
}
