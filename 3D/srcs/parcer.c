/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:41:00 by hballaba          #+#    #+#             */
/*   Updated: 2020/10/14 10:37:09 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int		check_color_end(char *line)
{
	int color;

	while (*line == ' ')
		line++;
	if (!(ft_isdigit(line[0])))
		print_error("Invalid color\n");
	color = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	if (ft_isprint(*line))
		print_error("Invalid color\n");
	return (color);
}

static int		check_color(char *line)
{
	int color;

	while (*line == ' ')
		line++;
	if (!(ft_isdigit(line[0])))
		print_error("Invalid color\n");
	color = ft_atoi(line);
	return (color);
}

void			ft_parcer_f_c(t_all *game, char *line, int i)
{
	int red;
	int green;
	int blue;

	red = -1;
	green = -1;
	blue = -1;
	line = line + 2;
	red = check_color(line);
	while (*line != ',' && *line != '\0')
		line++;
	*line == '\0' ? print_error("No valid map wall\n") : line++;
	green = check_color(line);
	while (*line != ',' && *line != '\0')
		line++;
	*line == '\0' ? print_error("No valid map wall\n") : line++;
	blue = check_color_end(line);
	if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || \
		blue > 255)
		print_error("No valid map wall\n");
	if (i == 1)
		game->tex->floor = ft_create_rgb(red, green, blue);
	if (i == 2)
		game->tex->ceilling = ft_create_rgb(red, green, blue);
}

void			ft_parcer_tex(t_all *game, char *line, int i)
{
	char *tmp;

	tmp = line;
	while (*line == ' ')
		line++;
	if (*line == 'R')
		i = ft_parcer_r(game, ++line);
	else if (*line == 'N' && line[1] == 'O' && line[2] == ' ')
		ft_parcer_no_so_we_ea(game, ++line, 1);
	else if (*line == 'S' && line[1] == 'O' && line[2] == ' ')
		ft_parcer_no_so_we_ea(game, ++line, 2);
	else if (*line == 'W' && line[1] == 'E' && line[2] == ' ')
		ft_parcer_no_so_we_ea(game, ++line, 3);
	else if (*line == 'E' && line[1] == 'A' && line[2] == ' ')
		ft_parcer_no_so_we_ea(game, ++line, 4);
	else if (*line == 'S' && line[1] == ' ')
		ft_parcer_no_so_we_ea(game, line, 5);
	else if (*line == 'F' && line[1] == ' ')
		ft_parcer_f_c(game, line, 1);
	else if (*line == 'C' && line[1] == ' ')
		ft_parcer_f_c(game, line, 2);
	if (i < 0)
		print_error("There is no such file with map\n");
}

void			ft_parser(t_all *game, int fd, int i, int flag)
{
	char	*line;
	t_list	*head;

	head = NULL;
	line = NULL;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (line[i] == 'R' || line[i] == 'N' || line[i] == 'S' || \
		line[i] == 'W' || line[i] == 'E' || line[i] == 'F' || line[i] == 'C')
			ft_parcer_tex(game, line, 1);
		else if (line[i] == '1')
		{
			ft_lstadd_back(&head, ft_lstnew(line));
			flag = 1;
		}
		else if ((line[i] == '\0' || line[i] == '\n') && flag == 0)
			i = 0;
		else
			print_error("No valid map\n");
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(&head, ft_lstsize(head), game, fd);
}
