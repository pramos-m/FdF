/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:56:27 by pramos-m          #+#    #+#             */
/*   Updated: 2023/02/24 14:09:49 by pramos-m         ###   ########.fr       */
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
	while (++i < mapdata->height)
	{
		bits = ft_split(columns[i], ' ');
		if (!bits)
			ft_error_handler(0, NULL);
		ft_pixel_put(bits, mapdata, i);
	}
}

void	ft_pixel_put(char **bits, t_map *mapdata, int y)
{
	static int	i = 0;
	int			x;
	char		**hex;

	x = -1;
	while (++x < mapdata->width)
	{
		if (ft_strchr(bits[x], ','))
		{
			hex = ft_split(bits[x], ',');
			if (!hex)
				ft_error_handler(0, NULL);
			mapdata->pixels[i].z = ft_atoi(hex[0]);
			mapdata->pixels[i].color = ft_atoi_base(&hex[1][2], 16);
		}
		else
			mapdata->pixels[i].z = ft_atoi(bits[x]);
		mapdata->pixels[i].x = x - (mapdata->width / 2);
		mapdata->pixels[i].y = y - (mapdata->height / 2);
		i++;
	}

}
