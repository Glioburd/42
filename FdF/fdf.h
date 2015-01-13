/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 16:12:40 by gsauvair          #+#    #+#             */
/*   Updated: 2015/01/13 18:22:50 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <mlx.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./libft/libft.h"
# define BUFF_SIZE 4096
# define WHITE 0xFFFFFF
# define BLUE 0x4169E1
# define RED 0XFF0000
# define GREEN 0x008000
# define YELLOW 0XFFFF00
# define PINK 0xFF69B4
# define TEAL 0x008080
# define ORANGE 0XFFA500
# define MATRIX 0x32CD32

typedef	struct		s_env
{
	char			*argcolor;
	int				***tab;
	int				width;
	int				height;
	void			*mlx;
	void			*win;
	int				movex;
	int				movey;
	int				zoom;
	int				length;
	int				**t_tab;
	int				move_x;
	int				move_y;
	int				move_y_z;
	int				move_x_z;
	float			high;
	int				color;
}					t_env;

int					ft_open(int fd, char **line);
int					*ft_atoi_width(char *str, int *width);
int					**ft_tab(char **str, int *length, int *width);
void				mi(int **tab, int length, int width, char *color);
int					ft_valid_args(int argc, char **argv, char **str);
void				ft_init_c(int *x, int *y, int *map, int **tab);
int					***ft_ini_coord(int **tab, int length, int width, t_env *e);
int					ft_pixel_put(t_env *e, int x, int y);
void				ft_pixel_start(t_env *e);
int					ft_expose_hook(t_env *e);
int					ft_keyhook2(int key, t_env *e);
int					ft_keyhook3(int key, t_env *e);
int					ft_mousehook(int mouse, int x, int y, t_env *e);
void				ft_coord(int *x, int *start, int alpha, int beta);
void				ft_draw_x(t_env *e, int i, int j);
void				ft_init_x(t_env *e);
void				ft_init_y(t_env *e);
void				ft_draw_y(t_env *e, int i, int j);
void				ft_write_op(t_env *e);
int					ft_arg_color(char *argvcolor, t_env *e);
void				ft_arg2_error(char *av);
int					ft_valid_arg2(char *av);

#endif
