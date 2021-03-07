/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 22:53:23 by hballaba          #+#    #+#             */
/*   Updated: 2020/05/15 22:53:27 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*bufdest;
	unsigned char	*bufsrc;
	size_t			i;

	i = 0;
	if (n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	bufdest = (unsigned char*)dest;
	bufsrc = (unsigned char*)src;
	if (bufdest > bufsrc)
	{
		while (i++ < n)
			bufdest[n - i] = bufsrc[n - i];
	}
	else
	{
		while (n > i)
		{
			bufdest[i] = bufsrc[i];
			i++;
		}
	}
	return (dest);
}
