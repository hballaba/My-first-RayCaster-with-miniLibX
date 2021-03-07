/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 12:56:30 by hballaba          #+#    #+#             */
/*   Updated: 2020/05/19 12:56:43 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **arr2, int i)
{
	while (i > 0)
	{
		i--;
		free(arr2[i]);
	}
	free(arr2);
	return (NULL);
}

static int	ft_number_word(char *s, char c)
{
	int word;
	int flag;

	word = 0;
	flag = 1;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		if (*s != c && flag == 1)
		{
			word++;
			flag = 0;
		}
		if (*s == c && flag == 0)
			flag = 1;
		s++;
	}
	return (word);
}

static int	ft_lenword(char *s, char c)
{
	size_t len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_split(char const *s, char c)
{
	char	**arr2;
	size_t	lenword;
	size_t	lenarr2;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	lenarr2 = ft_number_word((char*)s, c);
	arr2 = (char**)malloc(sizeof(char*) * (lenarr2 + 1));
	if (arr2 == NULL)
		return (NULL);
	while (lenarr2-- > 0)
	{
		while (*s == c && *s)
			s++;
		lenword = ft_lenword((char*)s, c);
		arr2[i] = ft_substr(s, 0, lenword);
		if (arr2[i] == NULL)
			ft_free(arr2, i);
		s = s + lenword;
		i++;
	}
	arr2[i] = NULL;
	return (arr2);
}
