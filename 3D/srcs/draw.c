/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:53:59 by hballaba          #+#    #+#             */
/*   Updated: 2020/10/13 12:33:31 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_draw_all(t_all *game)
{
	ft_draw_floor_celling(game);
	ft_cast_rays(game, game->zoom);
	ft_draw_sprite1(game);
	if (game->save == 0)
		mlx_put_image_to_window(game->img->mlx, game->img->win,\
		game->img->img, 0, 0);
	else
		ft_recoder(game);
}

void	ft_draw(t_all *game)
{
	game->img->mlx = mlx_init();
	if (game->tex->r_x > 2560)
		game->tex->r_x = 2560;
	if (game->tex->r_y > 1440)
		game->tex->r_y = 1440;
	game->rays->prog_plan = (game->tex->r_x / 2) / tan(PI / 6);
	game->img->win = mlx_new_window(game->img->mlx, game->tex->r_x, \
	game->tex->r_y, "Cub3D");
	if (game->img->win == NULL)
		print_error("No memory allocated for win\n");
	game->img->img = mlx_new_image(game->img->mlx, game->tex->r_x,\
	game->tex->r_y);
	if (game->img->img == NULL)
		print_error("No memory allocated for img\n");
	game->img->addr = mlx_get_data_addr(game->img->img, \
	&game->img->bits_per_pixel, &game->img->line_length, &game->img->endian);
	if (game->img->addr == NULL)
		print_error("No memory allocated for addr\n");
	game->zoom = 64;
	game->plr->x = game->plr->x * game->zoom + game->zoom / 2;
	game->plr->y = game->plr->y * game->zoom + game->zoom / 2;
	ft_draw_all(game);
	mlx_hook(game->img->win, 2, 1L << 0, key, game);
	mlx_hook(game->img->win, 17, 0, close_x, game);
	mlx_loop(game->img->mlx);
}
