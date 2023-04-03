/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:22:03 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/03 16:32:39 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	my_mlx_pixel_put(t_map *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));//Dst va a ser la direccion de memoria del primer pixel a imprimir. sumado de y * la length, y sumado por x * bytes (porque la direccion de x, no es 1, 2, 3, 4. Si no que cada posicion es la primera x los bytes que sean cada pixel (dividimos los bits y los onvertimos en bytes pq es un char *)).
		*(unsigned int *)dst = color;
	}
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

void	ft_copy(t_map	*mapdata)
{
	int	i;

	mapdata->pixels_copy = ft_calloc(sizeof(t_pixel), mapdata->size);
	if (!mapdata->pixels)
		ft_error_handler(0, NULL);
	i = -1;
	while (++i < mapdata->size)
		mapdata->pixels_copy[i] = mapdata->pixels[i];
}

void	ft_traslate(t_map	*mapdata)
{
	int	i;

	i = -1;
	while (++i < mapdata->size)
	{
		mapdata->pixels[i].x = mapdata->pixels[i].x + (WIN_WIDTH / 2);
		mapdata->pixels[i].y = mapdata->pixels[i].y + (WIN_HEIGHT / 2);
	}
}
