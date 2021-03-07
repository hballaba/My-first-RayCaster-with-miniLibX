/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:14:44 by hballaba          #+#    #+#             */
/*   Updated: 2020/10/13 16:41:58 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static float	ft_plr_dir(char dir)
{
	if (dir == 'E')
		return (0.0);
	else if (dir == 'N')
		return (PI * 3 / 2);
	else if (dir == 'W')
		return (PI);
	else if (dir == 'S')
		return (PI / 2);
	else
		return (0.0);
}

void			ft_plr(t_all *game, int i, int j)
{
	while (game->map[++i])
	{
		while (game->map[i][j])
		{
			if ((game->map[i][j] == 'N' && game->map[i][j + 1] != 'O') ||
			(game->map[i][j] == 'W' && game->map[i][j + 1] != 'E') ||
			(game->map[i][j] == 'E' && game->map[i][j + 1] != 'A') ||
			(game->map[i][j] == 'S' && game->map[i][j + 1] != 'O'))
			{
				game->plr->number++;
				game->plr->y = i;
				game->plr->x = j;
				game->plr->dir = ft_plr_dir(game->map[i][j]);
				game->map[i][j] = '0';
			}
			if (game->map[i][j] == '2')
				game->sprite->number++;
			j++;
		}
		j = 0;
	}
	if (game->plr->number > 1)
		print_error("Too mach players\n");
	if (game->plr->number == 0)
		print_error("No player\n");
}

void			ft_sprite(t_all *game, int i, int j, int s)
{
	int number;

	number = game->sprite->number;
	free(game->sprite);
	game->sprite = NULL;
	game->sprite = ft_calloc(sizeof(t_sprite), number + 1);
	if (game->sprite == NULL)
		print_error("No memory allocated for sprite\n");
	while (game->map[++i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] != '2' && game->map[i][j] != '1' \
			&& game->map[i][j] != '0' && game->map[i][j] != ' ')
				print_error("Other symbol in map\n");
			if (game->map[i][j] == '2')
			{
				game->sprite[s].x = j + 0.5;
				game->sprite[s].y = i + 0.5;
				s++;
			}
			j++;
		}
		j = 0;
	}
}
