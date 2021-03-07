/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 22:54:02 by hballaba          #+#    #+#             */
/*   Updated: 2020/05/24 11:34:54 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*res;

	size = 0;
	while (s[size])
		size++;
	res = (char*)malloc(sizeof(char) * size + 1);
	if (res == NULL)
		return (NULL);
	size = 0;
	while (s[size])
	{
		res[size] = s[size];
		size++;
	}
	res[size] = '\0';
	return (res);
}
