/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:31:28 by pramos-m          #+#    #+#             */
/*   Updated: 2023/03/08 16:58:43 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_error_handler(int error, char *strerror)
{
	if (!strerror && error)
	{
		if (error == ERRCODE0)
			write(STDERR_FILENO, ERR_MSG0, ft_strlen(ERR_MSG0));
	}
	else if (!error && strerror)
		write(STDERR_FILENO, strerror, ft_strlen(strerror));
	else if (!error && !strerror)
		perror("Error! ");
	exit(EXIT_FAILURE);
}

int	ft_line_len(char **bits)
{
	int			i;
	static int	x = 0;

	i = -1;
	while (bits[++i])
		;
	if (x == 0)
		x = i;
	else
		if (x != i)
			return (0);
	return (i);
}
void	my_mlx_pixel_put(t_map *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));//Dst va a ser la direccion de memoria del primer pixel a imprimir. sumado de y * la length, y sumado por x * bytes (porque la direccion de x, no es 1, 2, 3, 4. Si no que cada posicion es la primera x los bytes que sean cada pixel (dividimos los bits y los onvertimos en bytes pq es un char *)).
		*(unsigned int*)dst = color;
	}
}

int	exit_tutorial(t_map *mapdata)
{
	if (mapdata)
	{
		mlx_destroy_window (mapdata->mlx, mapdata->mlx_win);
		mlx_destroy_image (mapdata->mlx, mapdata->img);
	}
	free(mapdata->route);
	free(mapdata->content);
	free(mapdata->pixels);
	free(mapdata->pixels_copy);
	exit(EXIT_SUCCESS);
}

int	read_keys(int key_pressed, void *param)
{
	t_map	*img;

	img = (t_map *)param;
	if (key_pressed == ESC || !img)
		exit_tutorial(img);
	return (0);
}
void	ft_print_wallpaper(t_map *mapdata)
{
	int	y;
	int	x;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(mapdata, x, y, 0X222222);
			x++;
		}
		y++;
	}
	
}
float	ft_module(float x, float y)
{
	float		len;

	len = sqrt((x * x) + (y * y));
	return (len);
}
