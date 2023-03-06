/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:44:52 by pramos-m          #+#    #+#             */
/*   Updated: 2023/02/22 17:22:36 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"
# include "stdio.h"
# include <math.h>

# define ESC 53

//Window

#define WIN_WIDTH	(int)1920
#define WIN_HEIGHT	(int)1080

// Error Codes
# define ERRCODE0	(int)0

// Error Messages
# define ERR_MSG0	(char *)"Error!\n"


typedef struct s_pixel {
	float	x;
	float	y;
	float	z;
	int		color;
}				t_pixel;

typedef struct s_map {
	char	*route;
	char	*content;
	char	**columns;
	char	**bits;
	int		width;
	int		height;
	int		size;
	//window
	t_pixel	*pixels;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_map;


//	Map Cheking
void	ft_check_map(char *route, t_map *mapdata);
int		ft_read_check(int *fd, t_map *mapdata);
int		ft_check_content(int x, int y, t_map *mapdata);
int		ft_check_bits(char **bits);
int		ft_line_len(char **bits);
int		ft_check_hexa(char *str);

//	Map Loading

void	ft_fill_pixels(t_map *mapdata);
void	ft_pixel_put(char **bits, t_map *mapdata, int y);

//Window

void	my_mlx_pixel_put(t_map *data, int x, int y, int color);
int		read_keys(int key_pressed, void *param);
void	ft_window_create(t_map	*mapdata);

//print win
void	ft_print_win(t_map	*mapdata);
void	ft_traslate(t_map	*mapdata);
void	ft_escale(t_map	*mapdata);
void	ft_print_map(t_map	*mapdata);
void	my_mlx_pixel_put(t_map *data, int x, int y, int color);
void	ft_print_line(t_map	*mapdata, t_pixel a, t_pixel b);

//Utils
int		exit_tutorial(t_map *window);
void	ft_error_handler(int error, char *strerror);

#endif
