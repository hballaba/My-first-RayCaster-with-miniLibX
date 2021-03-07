/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 22:55:03 by hballaba          #+#    #+#             */
/*   Updated: 2020/05/15 22:55:11 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (n > 0 && str1[i] == str2[i] && (str1[i] || str2[i]))
	{
		n--;
		i++;
	}
	if (n == 0)
		i--;
	if (str2[i] != str1[i])
		return (str1[i] - str2[i]);
	else
		return (0);
}
