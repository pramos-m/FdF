/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:47:33 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/03 17:50:44 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_change_iso(t_map	*mapdata)
{
	int	i;
	int	x;

	i = -1;
	while (++i < mapdata->size)
	{
		x = mapdata->pixels[i].x;
		mapdata->pixels[i].x = (x - mapdata->pixels[i].y) * cos(0.90);
		mapdata->pixels[i].y = (x + mapdata->pixels[i].y)
			* sin(0.60) - mapdata->pixels[i].z;
	}
}

void	ft_escale(t_map	*mapdata)
{
	int		i;
	float	scale;

	i = -1;
	scale = (float)(WIN_HEIGHT - mapdata->height / 2)
		/ ft_module(mapdata->width, mapdata->height);
	while (++i < mapdata->size)
	{
		mapdata->pixels[i].x = mapdata->pixels[i].x * (scale);
		mapdata->pixels[i].y = mapdata->pixels[i].y * scale;
	}
}

void	ft_propotion_z(t_map	*mapdata)
{
	int			i;
	long int	dif_z;
	int			todivide;
	static int	divisor;
	float		scale;

	i = -1;
	scale = (float)(WIN_HEIGHT - mapdata->height / 2)
		/ ft_module(mapdata->width, mapdata->height);
	dif_z = (long int)(mapdata->max_z - mapdata->min_z);
	dif_z = labs(dif_z);
	todivide = dif_z / 32;
	divisor = 5;
	if (todivide > 1)
		divisor = 10 + scale;
	while (++i < mapdata->size)
		mapdata->pixels[i].z = mapdata->pixels[i].z / divisor;
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
				ft_print_line(mapdata, mapdata->pixels[p],
					mapdata->pixels[p + 1]);
			if (p + mapdata->width < mapdata->size)
				ft_print_line(mapdata, mapdata->pixels[p],
					mapdata->pixels[p + mapdata->width]);
			if (x < mapdata->width - 1)
				p++;
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
		toprint.x += increment.x;
		toprint.y += increment.y;
	}
}
