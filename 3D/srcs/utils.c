/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:51:44 by hballaba          #+#    #+#             */
/*   Updated: 2020/10/13 16:49:03 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		ft_create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_malloc_all(t_all *game)
{
	game->dot = (t_place*)malloc(sizeof(t_place));
	game->tex = (t_texture*)malloc(sizeof(t_texture));
	game->img = (t_data*)malloc(sizeof(t_data));
	game->plr = (t_player*)malloc(sizeof(t_player));
	game->sprite = (t_sprite*)malloc(sizeof(t_sprite));
	game->rays = (t_rays*)malloc(sizeof(t_rays));
	game->wall = (t_wall*)malloc(sizeof(t_wall));
	if (game->dot == NULL || game->tex == NULL || game->img == NULL \
	|| game->plr == NULL || game->sprite == NULL || game->wall == NULL)
	{
		print_error("No memory allocated for struct\n");
	}
	game->plr->x = 0.00;
	game->plr->number = 0;
	game->sprite->number = 0;
	game->save = 0;
}

void	print_error(char *error)
{
	ft_putstr_fd(error, 1);
	exit(1);
}

int		check_arg(int argc, char **argv, t_all *game)
{
	int fd;
	int i;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	if (argc == 1)
		print_error("Too few arguments\n");
	else if (argc > 3)
		print_error("Too mach arguments\n");
	else if (argc == 2 || argc == 3)
	{
		i = ft_strlen(argv[1]) - 1;
		if (argv[1][i] != 'b' || argv[1][i - 1] != 'u' ||\
			argv[1][i - 2] != 'c' || argv[1][i - 3] != '.')
			print_error("Other format than .cub\n");
	}
	if (argc == 3)
	{
		if (argv[2][0] != '-' || argv[2][1] != '-' || argv[2][2] != 's' || \
		argv[2][3] != 'a' || argv[2][4] != 'v' || argv[2][5] != 'e')
			print_error("Other argument than --save\n");
		else
			game->save = 1;
	}
	return (fd);
}
