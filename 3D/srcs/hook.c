/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:35:51 by hballaba          #+#    #+#             */
/*   Updated: 2020/10/13 13:43:39 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		ft_up(t_all *game)
{
	game->plr->y += sin(game->plr->dir) * game->zoom / 8;
	game->plr->x += cos(game->plr->dir) * game->zoom / 8;
}

static void		ft_down(t_all *game)
{
	game->plr->y -= sin(game->plr->dir) * game->zoom / 8;
	game->plr->x -= cos(game->plr->dir) * game->zoom / 8;
}

static void		ft_left(t_all *game)
{
	game->plr->y += sin(game->plr->dir - PI / 2) * 8;
	game->plr->x += cos(game->plr->dir - PI / 2) * 8;
}

static void		ft_right(t_all *game)
{
	game->plr->y -= sin(game->plr->dir - PI / 2) * 8;
	game->plr->x -= cos(game->plr->dir - PI / 2) * 8;
}

int				key(int keycode, t_all *game)
{
	if ((keycode >= 0 && keycode <= 13) || (keycode >= 123 && keycode <= 126))
	{
		if ((keycode == 13 || keycode == 126) && game->map[(int)((game->plr->y \
	+ sin(game->plr->dir) * game->zoom) / game->zoom)][(int)((game->plr->x \
	+ cos(game->plr->dir) * game->zoom) / game->zoom)] != '1')
			ft_up(game);
		else if ((keycode == 1 || keycode == 125) && game->map[(int)\
	((game->plr->y - sin(game->plr->dir) * game->zoom) / game->zoom)][(int)\
	((game->plr->x - cos(game->plr->dir) * game->zoom) / game->zoom)] != '1')
			ft_down(game);
		else if ((keycode == 0) && game->map[(int)((game->plr->y + \
	sin(game->plr->dir - PI / 2) * 32) / game->zoom)][(int)((game->plr->x + \
	cos(game->plr->dir - PI / 2) * 32) / game->zoom)] != '1')
			ft_left(game);
		else if ((keycode == 2) && game->map[(int)((game->plr->y - \
	sin(game->plr->dir - PI / 2) * 32) / game->zoom)][(int)((game->plr->x - \
	cos(game->plr->dir - PI / 2) * 32) / game->zoom)] != '1')
			ft_right(game);
		else if (keycode == 123 || keycode == 124)
			ft_change_dir(keycode, game);
		ft_draw_all(game);
	}
	if (keycode == 53)
		close_x(1, game);
	return (0);
}
