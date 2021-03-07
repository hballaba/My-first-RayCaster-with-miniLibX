/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:53:28 by hballaba          #+#    #+#             */
/*   Updated: 2020/10/13 14:49:11 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_no(t_all *game, char *line)
{
	int img_width;
	int img_height;
	int bits_per_pixel;
	int line_length;
	int endian;

	game->wall->no_mlx = mlx_init();
	if (game->wall->no_mlx == NULL)
		print_error("No memory allocated for no_mlx\n");
	game->wall->no_img = mlx_xpm_file_to_image(game->wall->no_mlx, line, \
	&img_width, &img_height);
	if (game->wall->no_img == NULL)
		print_error("No memory allocated for no_img\n");
	if (img_width != 64 || img_height != 64)
		print_error("Image no not 64x64 pixels\n");
	game->wall->no_addr = mlx_get_data_addr(game->wall->no_img,\
		&bits_per_pixel, &line_length, &endian);
	if (game->wall->no_addr == NULL)
		print_error("No memory allocated for no_addr\n");
	game->tex->no = line;
}

void	init_so(t_all *game, char *line)
{
	int img_width;
	int img_height;
	int bits_per_pixel;
	int line_length;
	int endian;

	game->wall->so_mlx = mlx_init();
	if (game->wall->so_mlx == NULL)
		print_error("No memory allocated for so_mlx\n");
	game->wall->so_img = mlx_xpm_file_to_image(game->wall->so_mlx, line, \
		&img_width, &img_height);
	if (game->wall->so_img == NULL)
		print_error("No memory allocated for so_img\n");
	if (img_width != 64 || img_height != 64)
		print_error("Image so not 64x64 pixels\n");
	game->wall->so_addr = mlx_get_data_addr(game->wall->so_img, \
		&bits_per_pixel, &line_length, &endian);
	if (game->wall->so_addr == NULL)
		print_error("No memory allocated for so_addr\n");
	game->tex->so = line;
}

void	init_we(t_all *game, char *line)
{
	int img_width;
	int img_height;
	int bits_per_pixel;
	int line_length;
	int endian;

	game->wall->we_mlx = mlx_init();
	if (game->wall->we_mlx == NULL)
		print_error("No memory allocated for we_mlx\n");
	game->wall->we_img = mlx_xpm_file_to_image(game->wall->we_mlx, line, \
		&img_width, &img_height);
	if (game->wall->we_img == NULL)
		print_error("No memory allocated for we_img\n");
	if (img_width != 64 || img_height != 64)
		print_error("Image we not 64x64 pixels\n");
	game->wall->we_addr = mlx_get_data_addr(game->wall->we_img,\
		&bits_per_pixel, &line_length, &endian);
	game->tex->we = line;
}

void	init_ea(t_all *game, char *line)
{
	int img_width;
	int img_height;
	int bits_per_pixel;
	int line_length;
	int endian;

	game->wall->ea_mlx = mlx_init();
	if (game->wall->ea_mlx == NULL)
		print_error("No memory allocated for ea_mlx\n");
	game->wall->ea_img = mlx_xpm_file_to_image(game->wall->ea_mlx, \
		line, &img_width, &img_height);
	if (game->wall->ea_img == NULL)
		print_error("No memory allocated for ea_img\n");
	if (img_width != 64 || img_height != 64)
		print_error("Image ea not 64x64 pixels\n");
	game->wall->ea_addr = mlx_get_data_addr(game->wall->ea_img, \
		&bits_per_pixel, &line_length, &endian);
	if (game->wall->ea_addr == NULL)
		print_error("No memory allocated for ea_addr\n");
	game->tex->ea = line;
}

void	init_s(t_all *game, char *line)
{
	int img_width;
	int img_height;
	int bits_per_pixel;
	int line_length;
	int endian;

	game->wall->s_mlx = mlx_init();
	if (game->wall->s_mlx == NULL)
		print_error("No memory allocated for sprite_mlx\n");
	game->wall->s_img = mlx_xpm_file_to_image(game->wall->s_mlx, line, \
		&img_width, &img_height);
	if (game->wall->s_img == NULL)
		print_error("No memory allocated for sprite_img\n");
	game->wall->s_addr = mlx_get_data_addr(game->wall->s_img, &bits_per_pixel, \
	&line_length, &endian);
	if (game->wall->s_addr == NULL)
		print_error("No memory allocated for sprite_addr\n");
	game->tex->s = line;
	game->wall->sprite_height = img_height;
	game->wall->sprite_width = img_width;
	game->wall->sprite_bits_per_pixel = bits_per_pixel;
	game->wall->sprite_line_length = line_length;
	game->wall->sprite_endian = endian;
}
