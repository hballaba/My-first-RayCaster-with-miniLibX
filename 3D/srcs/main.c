/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:36:24 by hballaba          #+#    #+#             */
/*   Updated: 2020/10/13 14:50:49 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_all	game;

	ft_malloc_all(&game);
	if ((fd = check_arg(argc, argv, &game)) < 0)
		print_error("Тo map file\n");
	ft_parser(&game, fd, 0, 0);
	ft_plr(&game, -1, 0);
	ft_sprite(&game, -1, 0, 0);
	ft_check_map(game.map, game.size_map - 1, &game);
	ft_check_tex(game.tex, 0);
	ft_draw(&game);
	return (0);
}
