/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:55:35 by hballaba          #+#    #+#             */
/*   Updated: 2020/10/13 14:54:53 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_lstclear_cub(t_list **lst)
{
	t_list	*clean;
	t_list	*buffer;

	clean = *lst;
	while (clean)
	{
		buffer = clean->next;
		free(clean);
		clean = buffer;
	}
	*lst = NULL;
}

void	make_map(t_list **head, int size, t_all *game, int fd)
{
	int		i;
	t_list	*tmp;

	game->map = (char**)malloc(sizeof(char*) * (size + 1));
	if (!game->map)
		print_error("No memory allocated for map\n");
	tmp = *head;
	i = 0;
	game->size_map = size;
	while (tmp)
	{
		game->map[i] = (char*)malloc(sizeof(char) * \
			(ft_strlen(tmp->content) + 1));
		if (!game->map[i])
			print_error("No memory allocated for map\n");
		ft_memcpy(game->map[i], tmp->content, ft_strlen(tmp->content) + 1);
		tmp = tmp->next;
		i++;
	}
	game->map[i] = NULL;
	ft_lstclear_cub(head);
	close(fd);
}
