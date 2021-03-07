/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 20:05:47 by hballaba          #+#    #+#             */
/*   Updated: 2020/10/13 12:01:23 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		ft_parc_ray(t_all *game, float x, float y, float ray_start)
{
	game->rays->dist = sqrt(((game->plr->x - x) * (game->plr->x - x)) + \
		((game->plr->y - y) * (game->plr->y - y)));
	game->rays->dist = game->rays->dist * cos(game->plr->dir - ray_start);
	game->rays->height = game->zoom / game->rays->dist * game->rays->prog_plan;
	game->rays->height = game->rays->height / 2 * 2;
	if (game->map[(int)((y - 0.1) / game->zoom)][(int)(x / game->zoom)] != '1')
		game->rays->tex = 's';
	else if (game->map[(int)((y + 0.1) / game->zoom)]\
			[(int)(x / game->zoom)] != '1')
		game->rays->tex = 'n';
	else if (game->map[(int)((y) / game->zoom)]\
			[(int)((x - 0.1) / game->zoom)] != '1')
		game->rays->tex = 'w';
	else if (game->map[(int)((y) / game->zoom)]\
			[(int)((x + 0.1) / game->zoom)] != '1')
		game->rays->tex = 'e';
	else
		game->rays->tex = 'b';
	game->rays->x = x;
	game->rays->y = y;
}

static void		ft_ray_sprite(t_all *game, t_player *ray, int x_pix, int num)
{
	game->map[(int)(ray->y / game->zoom)][(int)(ray->x / game->zoom)] = '3';
	game->sprite[num].x = (int)(ray->x / game->zoom) + 0.5;
	game->sprite[num].y = (int)(ray->y / game->zoom) + 0.5;
	game->sprite->curent_num = num;
	game->sprite[num].x_pix = x_pix;
	game->sprite[num].dot_x = ray->x;
	game->sprite[num].dot_y = ray->y;
	if (game->map[(int)((ray->y - 0.1) / game->zoom)]\
			[(int)(ray->x / game->zoom)] != '3')
		game->sprite[num].tex = 's';
	else if (game->map[(int)((ray->y + 0.1) / game->zoom)]\
			[(int)(ray->x / game->zoom)] != '3')
		game->sprite[num].tex = 'n';
	else if (game->map[(int)((ray->y) / game->zoom)]\
			[(int)((ray->x - 0.1) / game->zoom)] != '3')
		game->sprite[num].tex = 'w';
	else if (game->map[(int)((ray->y) / game->zoom)]\
			[(int)((ray->x + 0.1) / game->zoom)] != '3')
		game->sprite[num].tex = 'e';
	else
		game->sprite[num].tex = 'b';
}

static void		ft_init_ray(t_player *ray, t_all *game)
{
	ray->start = ray->dir - (PI / 6);
	ray->end = ray->dir + PI / 6;
	ray->x_pix = -1;
	ray->x = game->plr->x;
	ray->y = game->plr->y;
	ray->step = 0;
	ray->num_sprite = 0;
}

void			ft_cast_rays(t_all *game, double zoom)
{
	t_player	ray;

	ray = *game->plr;
	ft_init_ray(&ray, game);
	ray.num_sprite = -1;
	while (ray.start <= ray.end)
	{
		ray.x = game->plr->x;
		ray.y = game->plr->y;
		ray.step = 0;
		ray.sin = sin(ray.start);
		ray.cos = cos(ray.start);
		while (game->map[(int)(ray.y / zoom)][(int)(ray.x / zoom)] != '1')
		{
			ray.x = game->plr->x + ray.step * ray.cos;
			ray.y = game->plr->y + ray.step * ray.sin;
			ray.step += 0.1;
			if (game->map[(int)(ray.y / zoom)][(int)(ray.x / zoom)] == '2')
				ft_ray_sprite(game, &ray, ray.x_pix, ++ray.num_sprite);
		}
		ft_parc_ray(game, ray.x, ray.y, ray.start);
		ft_draw_wall(game, ++ray.x_pix);
		game->plr->ray_dist[ray.x_pix] = game->rays->dist;
		ray.start += PI / 3 / game->tex->r_x;
	}
}
