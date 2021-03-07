/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 22:52:22 by hballaba          #+#    #+#             */
/*   Updated: 2020/05/15 22:52:26 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	simbol;
	size_t			i;

	i = 0;
	str = (unsigned char*)s;
	simbol = (unsigned char)c;
	while (n > i)
	{
		if (simbol == str[i])
			return (str + i);
		i++;
	}
	return (NULL);
}
