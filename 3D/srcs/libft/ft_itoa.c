/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 19:27:18 by hballaba          #+#    #+#             */
/*   Updated: 2020/05/18 19:27:26 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long int number)
{
	int	i;

	i = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		number = number * (-1);
		i = 1;
	}
	while (number > 0)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	long int	number;
	char		*str;
	size_t		i;

	number = n;
	i = ft_len(number);
	str = (char*)malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	if (number == 0)
		str[0] = 48;
	if (number < 0)
	{
		str[0] = '-';
		number *= -1;
	}
	while (number > 0)
	{
		str[--i] = number % 10 + 48;
		number /= 10;
	}
	return (str);
}
