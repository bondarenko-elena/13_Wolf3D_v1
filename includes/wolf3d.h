/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 16:08:04 by olbondar          #+#    #+#             */
/*   Updated: 2018/07/08 16:42:21 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>


# define WIDTH 500
# define HEIGHT 500

// for MAC OS key_code == 53; for Debian key_code == 65307
# define KEY_ESC 53

typedef struct		s_dxy
{
	double			x;
	double			y;
}					t_dxy;

typedef struct		s_player
{
	struct s_dxy	position;
	struct s_dxy	direction;
	struct s_dxy	plane;
	double			speed_turn;
	double			speed_move;
	int				z;
	char			is_jump;
	char			move_left;
	char			move_right;
	char			move_up;
	char			move_down;
	char			move_jump;
}					t_player;

typedef struct		s_env
{
	char			*get_data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	void			*image;
	void			*mlx_init;
	void			*window;
	int 			width;
	int 			height;
	char 			*screen_name;
	unsigned int 	color_sky;
	unsigned int 	color_ground;
	unsigned int 	color_1;
	unsigned int 	color_2;
	unsigned int 	color_3;
	unsigned int 	color_4;
	struct s_player player;
	int 			**map;
	int 			map_height;
	int 			map_width;

}					t_env;


int					main(int argc, char **argv);
int 				check_file(char *filename);
t_env 				*pre_init_env();
void  				init_player(t_env *t_env);
void				post_init_env(t_env *env);
void 				malloc_error();
int 				open_file(t_env *env, char *filename);
void 				read_file(int fd, t_env *env);
void 				event(t_env *env);
int					key_hook(int keycode, t_env *env);
int 				expose_hook(t_env *env);
void 				display(t_env *env);
void 				put_pixel(t_env *env, int x, int y);
void 				get_position(int fd, t_env *env);
void 				read_line(char *line, int y, int **map, t_env *env);
void				map_error();


#endif
