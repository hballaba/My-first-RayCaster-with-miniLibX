/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:43:48 by hballaba          #+#    #+#             */
/*   Updated: 2020/10/13 18:50:35 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "../srcs/libft/libft.h"
# include "../includes/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define PI 3.141593

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct		s_texture
{
	int				r_x;
	int				r_y;
	char			*so;
	char			*we;
	char			*no;
	char			*ea;
	char			*s;
	int				floor;
	int				ceilling;
	int				temp_x;
	int				temp_y;
	double			prop_x;
	double			prop_y;
}					t_texture;

typedef struct		s_wal
{
	int				i;
	int				color;
	int				y_up;
	int				y_down;
	int				y_mid;
	int				y;
	int				x_pix;
	double			y_pix;
	double			y_prop;
	char			*tex;
}					t_wal;

typedef struct		s_player
{
	float			x;
	float			y;
	int				tmp_x;
	int				tmp_y;
	int				x_tmp_x;
	int				x_tmp_y;
	int				y_tmp_x;
	int				y_tmp_y;
	float			dir;
	float			start;
	float			end;
	int				number;
	float			step;
	int				flagx;
	int				flagy;
	int				x_pix;
	float			cos;
	float			sin;
	int				num_sprite;
	double			ray_dist[2560];
}					t_player;

typedef struct		s_sprite
{
	float			x;
	float			y;
	int				dot_x;
	int				dot_y;
	int				number;
	float			dist;
	float			dir;
	float			hight;
	float			step;
	float			width;
	float			ystart;
	float			xstart;
	int				curent_num;
	int				x_pix;
	char			tex;
	int				yes;
	int				y_offset;
	int				x_offset;
	int				size;
	int				sss_x;
	int				sss_y;
	int				sixe_x;
	int				size_y;
}					t_sprite;

typedef struct		s_place
{
	int				x;
	int				y;
	int				tmp_x;
	int				tmp_y;
}					t_place;

typedef struct		s_rays
{
	int				dist;
	int				height;
	int				x;
	int				y;
	char			tex;
	int				prog_plan;
	float			step;
}					t_rays;

typedef struct		s_wall
{
	void			*no_mlx;
	void			*so_mlx;
	void			*we_mlx;
	void			*ea_mlx;
	void			*s_mlx;
	void			*no_img;
	void			*so_img;
	void			*we_img;
	void			*ea_img;
	void			*s_img;
	char			*no_addr;
	char			*so_addr;
	char			*we_addr;
	char			*ea_addr;
	char			*s_addr;
	double			temp_x;
	double			temp_y;
	double			prop_x;
	double			prop_y;
	int				img_width;
	int				img_height;
	int				sprite_width;
	int				sprite_height;
	int				sprite_bits_per_pixel;
	int				sprite_line_length;
	int				sprite_endian;
}					t_wall;

typedef struct		s_all
{
	t_data			*img;
	t_place			*dot;
	t_player		*plr;
	t_texture		*tex;
	t_sprite		*sprite;
	t_rays			*rays;
	t_wall			*wall;
	char			**map;
	int				size_map;
	int				width_map;
	double			zoom;
	int				save;
}					t_all;

typedef struct		s_pic_sprite
{
	float			y_pix;
	float			x_pix;
	float			x_prop;
	float			y_prop;
	unsigned int	color;
	float			x;
	float			y;
	int				size_x;
	int				size_y;
	int				size;
}					t_pic_sprite;

void				ft_recoder(t_all *game);
void				ft_cast_rays(t_all *game, double zoom);
void				ft_check_map(char **map, int size, t_all *game);
void				ft_check_tex(t_texture *tex, int i);
void				ft_draw_sprite1(t_all *game);
void				ft_draw_wall(t_all *game, int x);
void				ft_draw_floor_celling(t_all *game);
void				ft_draw_all(t_all *game);
void				ft_draw(t_all *game);
int					key(int keycode, t_all *game);
int					close_x(int keycode, t_all *game);
void				init_s(t_all *game, char *line);
void				init_ea(t_all *game, char *line);
void				init_we(t_all *game, char *line);
void				init_so(t_all *game, char *line);
void				init_no(t_all *game, char *line);
void				ft_lstclear_cub(t_list **lst);
void				make_map(t_list **head, int size, t_all *game, int fd);
void				ft_parcer_no_so_we_ea(t_all *game, char *line, int i);
int					ft_parcer_r(t_all *game, char *line);
void				ft_parcer_f_c(t_all *game, char *line, int i);
void				ft_parcer_tex(t_all *game, char *line, int i);
void				ft_parser(t_all *game, int fd, int i, int flag);
void				ft_plr(t_all *game, int i, int j);
void				ft_sprite(t_all *game, int i, int j, int s);
void				ft_malloc_all(t_all *game);
int					ft_create_rgb(int r, int g, int b);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
unsigned int		get_map_color_wall(char *addr, int x, int y);
void				print_error(char *error);
int					check_arg(int argc, char **argv, t_all *game);
unsigned int		get_map_color_sprite(t_all *game, char *addr, int x, int y);
void				ft_change_dir(int keycode, t_all *game);
void				init_sprite(t_all *game, t_pic_sprite *sp, int num);

#endif
