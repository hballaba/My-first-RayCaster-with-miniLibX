/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 11:23:00 by hballaba          #+#    #+#             */
/*   Updated: 2020/05/17 11:23:04 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int ascii[256];
	int i;
	int end;

	if (!s1 || !set)
		return (NULL);
	i = -1;
	ft_memset(ascii, 0, sizeof(ascii));
	while (set[++i])
		ascii[(int)set[i]] = 1;
	i = 0;
	while (ascii[(int)s1[i]] == 1)
		i++;
	end = ft_strlen((char*)s1);
	while (ascii[(int)s1[end - 1]] == 1)
		end--;
	return (ft_substr(s1, i, end - i));
}
