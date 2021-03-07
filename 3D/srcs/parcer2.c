/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 10:25:01 by hballaba          #+#    #+#             */
/*   Updated: 2020/10/14 10:25:11 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_parcer_no_so_we_ea(t_all *game, char *line, int i)
{
	line = line + 2;
	if (i == 1)
		init_no(game, line);
	if (i == 2)
		init_so(game, line);
	if (i == 3)
		init_we(game, line);
	if (i == 4)
		init_ea(game, line);
	if (i == 5)
		init_s(game, line);
}

int		ft_parcer_r(t_all *game, char *line)
{
	while (*line == ' ')
		line++;
	game->tex->r_x = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ')
		line++;
	game->tex->r_y = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	if (*line || game->tex->r_x < 1 || game->tex->r_y < 1)
		print_error("invalid resolution\n");
	return (1);
}
