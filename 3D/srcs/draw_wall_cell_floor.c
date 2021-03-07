/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:37:57 by hballaba          #+#    #+#             */
/*   Updated: 2020/10/13 18:27:10 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned int	get_map_color_wall(char *addr, int x, int y)
{
	int				line_length;
	int				bits_per_pixel;
	char			*dst;
	unsigned int	color;

	line_length = 256;
	bits_per_pixel = 32;
	dst = addr + (y * line_length + x * (bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

static void		ft_wall_tex(int x, t_wal wall, t_all *game)
{
	wall.y_pix = 32;
	while (--wall.y > wall.y_up && wall.y > 0)
	{
		wall.y_pix = wall.y_pix - wall.y_prop;
		wall.color = get_map_color_wall(wall.tex, wall.x_pix, wall.y_pix);
		my_mlx_pixel_put(game->img, x, wall.y, wall.color);
	}
	wall.y = wall.y_mid;
	wall.y_pix = 32;
	while (wall.y < wall.y_down - 2 && wall.y < game->tex->r_y - 2)
	{
		wall.y_pix = wall.y_pix + wall.y_prop;
		wall.color = get_map_color_wall(wall.tex, wall.x_pix, wall.y_pix);
		my_mlx_pixel_put(game->img, x, wall.y, wall.color);
		wall.y++;
	}
}

void			ft_draw_wall(t_all *game, int x)
{
	t_wal wall;

	if (game->rays->tex == 'n' || game->rays->tex == 's')
		wall.x_pix = (game->rays->x - game->rays->x / (int)game->zoom \
				* (int)game->zoom) * 64 / game->zoom;
	else
		wall.x_pix = (game->rays->y - game->rays->y / (int)game->zoom \
				* (int)game->zoom) * 64 / game->zoom;
	wall.y_up = game->tex->r_y / 2 - game->rays->height / 2;
	wall.y_down = game->tex->r_y / 2 + game->rays->height / 2;
	wall.y_mid = game->tex->r_y / 2;
	wall.y = wall.y_mid + 1;
	if (game->rays->tex == 'n')
		wall.tex = game->wall->no_addr;
	else if (game->rays->tex == 's')
		wall.tex = game->wall->so_addr;
	else if (game->rays->tex == 'w')
		wall.tex = game->wall->we_addr;
	else
		wall.tex = game->wall->ea_addr;
	wall.y_prop = 64 / (double)game->rays->height;
	ft_wall_tex(x, wall, game);
}

void			ft_draw_floor_celling(t_all *game)
{
	int x;
	int y;

	y = game->tex->r_y / 2;
	while (y < game->tex->r_y)
	{
		x = -1;
		while (++x < game->tex->r_x)
			my_mlx_pixel_put(game->img, x, y, game->tex->floor);
		y++;
	}
	y = 0;
	x = 0;
	while (y < game->tex->r_y / 2)
	{
		x = -1;
		while (++x < game->tex->r_x)
			my_mlx_pixel_put(game->img, x, y, game->tex->ceilling);
		y++;
	}
}
