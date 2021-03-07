/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:30:28 by hballaba          #+#    #+#             */
/*   Updated: 2020/10/13 17:49:38 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		ft_make_img_bmp(t_all *game, int x, int y)
{
	int		i;
	int		fd;
	int		*dst;

	while (--y >= 0)
	{
		i = -1;
		while (++i < x)
		{
			fd = open("cub.bmp", O_RDWR | O_CREAT | O_APPEND, S_IRWXU);
			dst = (int*)(game->img->addr + (y * game->img->line_length + \
				(x + i) * (game->img->bits_per_pixel / 8)));
			write(fd, dst, 4);
			close(fd);
		}
	}
}

static void		ft_bitmap(void *temp, int size)
{
	int fd;

	fd = open("cub.bmp", O_RDWR | O_CREAT | O_APPEND, S_IRWXU);
	write(fd, temp, size);
	close(fd);
}

static void		ft_zero_record(int temp, int num)
{
	while (--num >= 0)
		ft_bitmap(&temp, 4);
}

void			ft_recoder(t_all *game)
{
	int		temp_4;
	short	temp_2;

	temp_2 = 0x4D42;
	ft_bitmap(&temp_2, 2);
	temp_4 = 54 + (game->tex->r_x * game->tex->r_y) * 4;
	ft_bitmap(&temp_4, 4);
	temp_4 = 0;
	ft_bitmap(&temp_4, 4);
	temp_4 = 54;
	ft_bitmap(&temp_4, 4);
	temp_4 = 40;
	ft_bitmap(&temp_4, 4);
	temp_4 = game->tex->r_x;
	ft_bitmap(&temp_4, 4);
	temp_4 = game->tex->r_y;
	ft_bitmap(&temp_4, 4);
	temp_2 = 0x0001;
	ft_bitmap(&temp_2, 2);
	temp_2 = 0x0020;
	ft_bitmap(&temp_2, 2);
	ft_zero_record(0, 6);
	ft_make_img_bmp(game, game->tex->r_x, game->tex->r_y);
	exit(0);
}
