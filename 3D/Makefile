NAME = cub3D

OBJECT = ./object/init_texture.o ./object/main.o ./object/bitmap.o ./object/hook.o \
./object/hook_2.o ./object/player.o ./object/draw_wall_cell_floor.o ./object/parcer.o \
./object/check_map.o ./object/draw_sprite.o ./object/utils.o ./object/draw.o \
	./object/make_map.o ./object/cast_ray.o ./object/main.o  ./object/draw_sprite_2.o\
	./object/parcer2.o 


HEADER = ./includes/cub3d.h
DIR_SRC = ./srcs/
DIR_OBJ = ./object/
DIR_LIBFT = ./srcs/libft/
DIR_MLX = ./srcs/minilibx_opengl_20191021/
LIBFT_A = $(DIR_LIBFT)libft.a
LIBMLX_A = $(DIR_MLX)libmlx.a

FLAG = -Wextra -Werror -Wall
FLAG_MLX = -lmlx -framework OpenGL -framework AppKit

all: $(DIR_OBJ) $(NAME) 

$(DIR_OBJ):
	@mkdir $(DIR_OBJ)
	@make -C $(DIR_LIBFT) 
	@make -C $(DIR_MLX) 

$(NAME):  $(OBJECT) $(LIBFT_A) $(LIBMLX_A)
	@gcc -o $@ $^ $(FLAG_MLX)
%.o: %.c
	@gcc $(FLAG) - I $(HEADER) -c $< -o $@

$(DIR_OBJ)%.o:$(DIR_SRC)%.c
	@gcc -Wextra -Werror -Wall -I $(HEADER) -c $< -o $@ 
	
clean:
	@rm -f $(OBJECT)
	@make clean -C $(DIR_LIBFT)
	@rm -rf object
	@echo objects deleted

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(DIR_LIBFT) 
	@make clean -C $(DIR_MLX) 
	@rm -f ./cub3d
	@echo deleted

re: fclean all

bonus: re

.PHONY: all clean fclean re bonus
