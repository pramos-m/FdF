/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:47:33 by pramos-m          #+#    #+#             */
/*   Updated: 2023/03/12 20:33:47 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

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

void	ft_change_iso(t_map	*mapdata)
{
	int	i;
	int	x;

	i = -1;
	while (++i < mapdata->size)
	{
		x = mapdata->pixels[i].x;
		mapdata->pixels[i].x = (x - mapdata->pixels[i].y) * cos(0.82);
		mapdata->pixels[i].y = (x + mapdata->pixels[i].y)
			* sin(0.82) - mapdata->pixels[i].z;
	}
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

void	ft_escale(t_map	*mapdata)
{
	int		i;
	float	scale;

	i = -1;
	scale = (float)(WIN_HEIGHT - ft_module(mapdata->width, mapdata->height))
		/ ft_module(mapdata->width, mapdata->height);
	mapdata->depth = (WIN_WIDTH * WIN_WIDTH) / (mapdata->width * mapdata->height
            * pow(0,82 / 2) * log(mapdata->z + 2));
	printf("mapdata depth %f", mapdata->depth);
	while (++i < mapdata->size)
	{
		mapdata->pixels[i].x = mapdata->pixels[i].x * (scale);
		mapdata->pixels[i].y = (((mapdata->pixels[i].x + mapdata->pixels[i].y) * sin(8.02)) * (scale - mapdata->pixels[i].z * mapdata->depth) - mapdata->pixels[i].y) + WIN_HEIGHT / 2.0;
	}
}


void	ft_propotion_z(t_map	*mapdata)
{
	int				i;
	long int		dif_z;
	int				todivide;
	static int		divisor;
	float			scale;

	i = -1;
	dif_z = (long int)(mapdata->max_z - mapdata->min_z);
	mapdata->z = labs(dif_z);
	todivide = dif_z / 32;
	if (todivide < 1)
		divisor = 5;
	else
		divisor = dif_z / 32;
	scale = (float)(WIN_HEIGHT - mapdata->height / 2)
		/ ft_module(mapdata->width, mapdata->height);
	while (++i < mapdata->size)
	{
		if (((float)dif_z / 2) > ((float)mapdata->width / 2) && ((float)dif_z) > ((float)mapdata->height))
			mapdata->pixels[i].z = mapdata->pixels[i].z / divisor;
	}
}

void	ft_print_map(t_map	*mapdata)
{
	int	x;
	int	y;
	int	p;

	p = 0;
	y = -1;
	while (++y < mapdata->height)
	{
		x = -1;
		while (++x < mapdata->width)
		{
			if (p + 1 < mapdata->size && mapdata->pixels_copy[p].y
				== mapdata->pixels_copy[p + 1].y)
				ft_print_line(mapdata, mapdata->pixels[p]
					, mapdata->pixels[p + 1]);
			if (p + mapdata->width < mapdata->size)
				ft_print_line(mapdata, mapdata->pixels[p],
					mapdata->pixels[p + mapdata->width]);
			if (x < mapdata->width - 1)
				p++;
			// printf("mapdata x : %f   mapdata y  %f \n", mapdata->pixels[p].x,  mapdata->pixels[p].y);
		}
		p++;
	}
}

void	ft_print_line(t_map	*mapdata, t_pixel a, t_pixel b)
{
	t_pixel	vector;
	t_pixel	increment;
	t_pixel	toprint;
	float	len;

	vector.x = b.x - a.x;
	vector.y = b.y - a.y;
	len = sqrt((vector.x * vector.x) + (vector.y * vector.y));
	increment.x = vector.x / len;
	increment.y = vector.y / len;
	toprint = a;
	while (len-- > 0)
	{
		my_mlx_pixel_put(mapdata, toprint.x, toprint.y, toprint.color);
		if (toprint.y > 1080)
			printf("mapdata x : %f   mapdata y  %f \n", toprint.x, toprint.y);
		toprint.x += increment.x;
		toprint.y += increment.y;
	}
}