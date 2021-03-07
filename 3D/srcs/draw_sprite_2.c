/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 17:58:12 by hballaba          #+#    #+#             */
/*   Updated: 2020/10/13 18:24:31 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			init_sprite(t_all *game, t_pic_sprite *sp, int num)
{
	sp->x_pix = 0;
	sp->x = -1;
	game->sprite[num].size = game->zoom / game->sprite[num].dist * \
	game->rays->prog_plan / game->zoom;
	game->sprite[num].x_offset = ((game->sprite[num].dir - game->plr->dir) * \
	(game->tex->r_x) + (game->tex->r_x / 2) - game->sprite[num].size / 2) + 10;
	game->sprite[num].y_offset = (game->tex->r_y /\
		2 - game->sprite[num].size / 2);
	sp->y_prop = (double)game->wall->sprite_height / \
		(double)game->sprite[num].size;
	sp->x_prop = (double)game->wall->sprite_width / \
		(double)game->sprite[num].size;
}

unsigned int	get_map_color_sprite(t_all *game, char *addr, int x, int y)
{
	int				line_length;
	int				bits_per_pixel;
	char			*dst;
	unsigned int	color;

	bits_per_pixel = game->wall->sprite_bits_per_pixel;
	line_length = game->wall->sprite_line_length;
	dst = addr + (y * line_length + x * (bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}
