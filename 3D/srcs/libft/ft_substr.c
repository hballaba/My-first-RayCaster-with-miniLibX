/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 10:31:59 by hballaba          #+#    #+#             */
/*   Updated: 2020/05/16 10:32:07 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*subline;

	i = ft_strlen((char*)s) + 1;
	if (len == 0 || i <= start)
		return (ft_strdup(""));
	if (i - start < len)
		len = i - start;
	subline = (char*)malloc(sizeof(char) * len + 1);
	if (subline == NULL)
		return (NULL);
	ft_memcpy(subline, s + start, len);
	subline[len] = '\0';
	return (subline);
}
