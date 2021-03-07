/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:44:31 by hballaba          #+#    #+#             */
/*   Updated: 2020/10/13 12:22:52 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		ft_check_0(int x, int y, char **map)
{
	int z;

	if ((map[y][x - 1] == '1' || map[y][x - 1] == '0' || map[y][x - 1] == '2')\
	&& (map[y][x + 1] == '1' || map[y][x + 1] == '0' || map[y][x + 1] == '2')\
	&& (map[y + 1][x] == '1' || map[y + 1][x] == '0' || map[y + 1][x] == '2')\
	&& (map[y - 1][x] == '1' || map[y - 1][x] == '0' || map[y - 1][x] == '2')\
	&& (map[y + 1][x + 1] == '1' || map[y + 1][x + 1] == '0' ||\
		map[y + 1][x + 1] == '2')\
	&& (map[y + 1][x - 1] == '1' || map[y + 1][x - 1] == '0' ||\
		map[y + 1][x - 1] == '2')\
	&& (map[y - 1][x + 1] == '1' || map[y - 1][x + 1] == '0' || \
		map[y - 1][x + 1] == '2')\
	&& (map[y - 1][x - 1] == '1' || map[y - 1][x - 1] == '0' || \
		map[y - 1][x - 1] == '2'))
		z = 0;
	else
		print_error("No valid map wall 0 with space\n");
}

static void		ft_check_map_wall(char **map)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '0' || map[y][x] == '2')
				ft_check_0(x, y, map);
			x++;
		}
		y++;
	}
}

static void		ft_equally_map(char **map, int size, t_all *game)
{
	int		i;
	char	*tmp;

	i = -1;
	game->width_map = 0;
	while (game->map[++i])
	{
		if (game->width_map < ft_strlen(game->map[i]))
			game->width_map = ft_strlen(game->map[i]);
	}
	i = -1;
	while (++i <= size)
	{
		if (ft_strlen(map[i]) < game->width_map)
		{
			tmp = map[i];
			game->map[i] = ft_calloc(sizeof(char), game->width_map + 1);
			if (!game->map[i])
				print_error("No memory allocated for map\n");
			ft_memset(game->map[i], ' ', game->width_map);
			game->map[i][game->width_map] = '\0';
			ft_memmove(game->map[i], tmp, ft_strlen(tmp));
			free(tmp);
		}
	}
}

void			ft_check_map(char **map, int size, t_all *game)
{
	int	i;

	i = 0;
	if (size < 2)
		print_error("No valid map, lines less than 3\n");
	while (map[0][i])
	{
		if (map[0][i] != '1' && map[0][i] != ' ')
			print_error("No valid map1\n");
		i++;
	}
	i = -1;
	while (map[size][++i])
	{
		if (map[size][i] != '1' && map[size][i] != ' ')
			print_error("No valid map2\n");
	}
	ft_check_map_wall(map);
	game->width_map = 5;
	ft_equally_map(map, size, game);
}

void			ft_check_tex(t_texture *tex, int i)
{
	if (tex->so == NULL || tex->ea == NULL || tex->we == NULL || \
	tex->s == NULL || tex->no == NULL)
		print_error("No wall tecture\n");
	i = ft_strlen(tex->so) - 1;
	if (tex->so[i] != 'm' || tex->so[i - 1] != 'p' || tex->so[i - 2] != 'x' ||\
	tex->so[i - 3] != '.')
		print_error("Invalid tecture SO\n");
	i = ft_strlen(tex->ea) - 1;
	if (tex->ea[i] != 'm' || tex->ea[i - 1] != 'p' || tex->ea[i - 2] != 'x' ||\
	tex->ea[i - 3] != '.')
		print_error("Invalid tecture\n");
	i = ft_strlen(tex->we) - 1;
	if (tex->we[i] != 'm' || tex->we[i - 1] != 'p' || tex->we[i - 2] != 'x' ||\
	tex->we[i - 3] != '.')
		print_error("Invalid tecture WE\n");
	i = ft_strlen(tex->s) - 1;
	if (tex->s[i] != 'm' || tex->s[i - 1] != 'p' || tex->s[i - 2] != 'x' ||\
	tex->s[i - 3] != '.')
		print_error("Invalid tecture S\n");
	i = ft_strlen(tex->no) - 1;
	if (tex->no[i] != 'm' || tex->no[i - 1] != 'p' || tex->no[i - 2] != 'x' ||\
	tex->no[i - 3] != '.')
		print_error("Invalid tecture NO\n");
}
