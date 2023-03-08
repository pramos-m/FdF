/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:56:27 by pramos-m          #+#    #+#             */
/*   Updated: 2023/03/08 13:27:31 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_fill_pixels(t_map *mapdata)
{
	char	**columns;
	char	**bits;
	int		i;

	mapdata->pixels = ft_calloc(sizeof(t_pixel), mapdata->size);
	if (!mapdata->pixels)
		ft_error_handler(0, NULL);
	columns = ft_split(mapdata->content, '\n');
	if (!columns)
		ft_error_handler(0, NULL);
	i = -1;
	mapdata->max_z = INT_MIN;
	mapdata->min_z = INT_MAX;
	while (++i < mapdata->height)
	{
		bits = ft_split(columns[i], ' ');
		if (!bits)
			ft_error_handler(0, NULL);
		ft_pixel_put(bits, mapdata, i);
		free(bits);
		free(columns[i]);
	}
	free(columns);
}

void	ft_pixel_put(char **bits, t_map *mapdata, int y)
{
	static int	i = 0;
	int			x;

	x = -1;
	while (++x < mapdata->width)
	{
		if (ft_strchr(bits[x], ','))
			mapdata->pixels[i].color = ft_atoi_base(ft_strchr(bits[x], ',') + 1, 16);
		if (ft_atoi(bits[x]) > mapdata->max_z)
			mapdata->max_z = ft_atoi(bits[x]);
		if (ft_atoi(bits[x]) < mapdata->min_z)
			mapdata->min_z = ft_atoi(bits[x]);
		mapdata->pixels[i].z = ft_atoi(bits[x]);
		mapdata->pixels[i].x = x - (mapdata->width / 2);
		mapdata->pixels[i].y = y - (mapdata->height / 2);
		free(bits[x]);
		i++;
	}

}
