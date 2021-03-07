/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 22:53:36 by hballaba          #+#    #+#             */
/*   Updated: 2020/05/15 22:53:40 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char*)s;
	while (n > 0)
	{
		dest[i] = c;
		n--;
		i++;
	}
	return (dest);
}
