/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 09:52:03 by hballaba          #+#    #+#             */
/*   Updated: 2020/09/23 13:16:33 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_copy(char *buf)
{
	size_t i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	buf[i] = '\0';
	return (buf);
}

char	*ft_gnlmemcpy(char *dest, char *src)
{
	char	*buf;
	char	*dst;
	size_t	i;

	if (!src && !dest)
		return (dest);
	dst = (char*)dest;
	buf = (char*)src;
	i = 0;
	while (src[i])
	{
		dst[i] = buf[i];
		i++;
	}
	dst[i] = '\0';
	free(src);
	src = NULL;
	dest = dst;
	return (dest);
}

int		workgnl(int fd, char **line, int size, int reader)
{
	static char	*repa[1];
	char		buf[size + 1];

	*line = ft_strdup("");
	if (!repa[fd])
	{
		if ((reader = read(fd, &buf, size)) < 0)
			return (-1);
	}
	else
		ft_gnlmemcpy(buf, repa[fd]);
	buf[reader] = '\0';
	while ((!(repa[fd] = ft_strchr(buf, '\n')) && reader == size))
	{
		*line = ft_strjoin(*line, ft_copy(buf));
		reader = read(fd, &buf, size);
		buf[reader] = '\0';
	}
	if (reader > 0)
		*line = ft_strjoin(*line, ft_copy(buf));
	if ((!repa[fd]) && reader < size)
		return (2);
	repa[fd] = ft_strdup(repa[fd]);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int		i;
	int		reader;
	int		size;

	size = 1;
	reader = size;
	if (fd < 0 || !line || size < 1)
		return (-1);
	i = workgnl(fd, line, size, reader);
	if (i == 2)
		return (0);
	return (i);
}
