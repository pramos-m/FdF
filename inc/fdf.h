/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:44:52 by pramos-m          #+#    #+#             */
/*   Updated: 2023/02/21 17:50:28 by pramos-m         ###   ########.fr       */
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
# define ERR_MSG4	(char *)"text\n"

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map {
	char	*route;
	char	*content;
	char	**columns;
	char	**bits;
}				t_map;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
//int	read_keys(int key_pressed, void *param);
void	ft_check_map(char *route, t_map *mapdata);
int		exit_tutorial(t_data *window);
int		ft_read_check(int *fd, t_map *mapdata);
void	ft_error_handler(int error);
int		ft_check_content(t_map *mapdata);
int		ft_check_bits(char **bits);
int		ft_line_len(char **bits);
int		ft_check_hexa(char *str);

#endif