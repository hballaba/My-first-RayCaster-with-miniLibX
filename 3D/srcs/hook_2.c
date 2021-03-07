/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:46:14 by hballaba          #+#    #+#             */
/*   Updated: 2020/10/13 13:43:26 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_change_dir(int keycode, t_all *game)
{
	if (keycode == 123)
		game->plr->dir = game->plr->dir - 0.05;
	else if (keycode == 124)
		game->plr->dir = game->plr->dir + 0.05;
}

int		close_x(int keycode, t_all *game)
{
	if (keycode == 0)
		game->zoom = 64;
	exit(1);
}
