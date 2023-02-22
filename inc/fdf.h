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

# define ESC 53

// Error Codes
# define ERRCODE0	(int)0
# define ERRCODE1	(int)1
# define ERRCODE2	(int)2
# define ERRCODE3	(int)3
# define ERRCODE4	(int)4

// Error Messages
# define ERR_MSG0	(char *)"Error!\n"
# define ERR_MSG1	(char *)"Error! Invalid parameters given!\n"
# define ERR_MSG2	(char *)"Error! Invalid File extension!\n"
# define ERR_MSG3	(char *)"Error reading File\n"
# define ERR_MSG4	(char *)"Error while loading map\n"

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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
	t_pixel	*pixels;
}				t_map;

//int	read_keys(int key_pressed, void *param);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		exit_tutorial(t_data *window);
void	ft_error_handler(int error);

//	Map Cheking
void	ft_check_map(char *route, t_map *mapdata);
int		ft_read_check(int *fd, t_map *mapdata);
int		ft_check_content(int x, int y, t_map *mapdata);
int		ft_check_bits(char **bits);
int		ft_line_len(char **bits);
int		ft_check_hexa(char *str);

//	Map Loading

void	ft_fill_pixels(t_map *mapdata);
void ft_pixel_put(char **bits, t_map *mapdata, int y);

#endif
