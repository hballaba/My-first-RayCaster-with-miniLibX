/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 22:54:14 by hballaba          #+#    #+#             */
/*   Updated: 2020/05/15 22:54:17 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t lendst;
	size_t lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen((char*)src);
	i = lendst + lensrc;
	if (size <= lendst)
		return (lensrc + size);
	while (*src && size > lendst + 1)
	{
		dst[lendst] = *src;
		src++;
		lendst++;
	}
	dst[lendst] = '\0';
	return (i);
}
