/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 20:03:40 by hballaba          #+#    #+#             */
/*   Updated: 2020/10/13 18:11:47 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		ft_sort_sprite1(t_all *game, int a, int num, int n)
{
	float	temp;

	while (num > ++n)
	{
		a = -1;
		while (++a < num - n)
		{
			if (game->sprite[a].dist < game->sprite[a + 1].dist)
			{
				temp = game->sprite[a].dist;
				game->sprite[a].dist = game->sprite[a + 1].dist;
				game->sprite[a + 1].dist = temp;
				temp = game->sprite[a].x;
				game->sprite[a].x = game->sprite[a + 1].x;
				game->sprite[a + 1].x = temp;
				temp = game->sprite[a].y;
				game->sprite[a].y = game->sprite[a + 1].y;
				game->sprite[a + 1].y = temp;
				temp = game->sprite[a].dir;
				game->sprite[a].dir = game->sprite[a + 1].dir;
				game->sprite[a + 1].dir = temp;
			}
		}
	}
}

static void		ft_pars_sprites_for_draw(t_all *game, int num, int y, int x)
{
	game->sprite[num].x = (x + 0.5) * game->zoom;
	game->sprite[num].y = (y + 0.5) * game->zoom;
	game->sprite->curent_num = num;
	game->sprite[num].dot_x = x;
	game->sprite[num].dot_y = y;
	game->sprite[num].dir = atan2(game->sprite[num].y - (double)game->plr->y,\
	game->sprite[num].x - (double)game->plr->x);
	while (game->sprite[num].dir - game->plr->dir > PI)
		game->sprite[num].dir -= 6.283186;
	while (game->sprite[num].dir - game->plr->dir < -PI)
		game->sprite[num].dir += 6.283186;
	game->sprite[num].dist = sqrt(pow((game->plr->x - game->sprite[num].x) /\
	game->zoom, 2) + \
	pow((game->plr->y - game->sprite[num].y) / game->zoom, 2)) * 0.9;
}

void			ft_draw_y(t_all *game, t_pic_sprite sp, int x, int num)
{
	sp.y = -1;
	sp.y_pix = 0;
	sp.y_prop = (double)game->wall->sprite_height /\
				(double)game->sprite[num].size;
	while (++sp.y < game->sprite[num].size - 2)
	{
		sp.y_pix = sp.y_pix + sp.y_prop;
		sp.color = get_map_color_sprite(game, game->wall->s_addr, \
				sp.x_pix, sp.y_pix);
		if (game->tex->r_y > game->sprite[num].y_offset + sp.y && 0 <\
		game->sprite[num].y_offset + sp.y && sp.color != 9961608 &&\
		sp.color != 4278190080)
			my_mlx_pixel_put(game->img, x, game->sprite[num].y_offset + \
			sp.y, sp.color);
	}
}

static void		ft_sprite_pic(t_all *game, int num)
{
	t_pic_sprite	sp;

	init_sprite(game, &sp, num);
	while (++sp.x <= game->sprite[num].size)
	{
		sp.x_pix = sp.x_pix + sp.x_prop;
		if (game->sprite[num].dist <= 0.6)
		{
			game->map[(int)(game->sprite[num].y / game->zoom)][(int)\
				(game->sprite[num].x / game->zoom)] = '0';
			break ;
		}
		if (game->tex->r_x > game->sprite[num].x_offset + sp.x && 0 < \
		game->sprite[num].x_offset + sp.x && game->plr->ray_dist[game->\
		sprite[num].x_offset + (int)sp.x] > game->sprite[num].dist * 64)
			ft_draw_y(game, sp, game->sprite[num].x_offset + sp.x, num);
	}
}

void			ft_draw_sprite1(t_all *game)
{
	int i;
	int j;
	int num;

	i = 0;
	num = -1;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '3')
			{
				game->map[i][j] = '2';
				ft_pars_sprites_for_draw(game, ++num, i, j);
			}
			j++;
		}
		i++;
	}
	ft_sort_sprite1(game, 0, num, -1);
	i = -1;
	while (num >= ++i)
		ft_sprite_pic(game, i);
}
