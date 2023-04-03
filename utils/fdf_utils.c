/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:31:28 by pramos-m          #+#    #+#             */
/*   Updated: 2023/04/03 16:33:04 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_error_handler(int error, char *strerror)
{
	if (!strerror && error)
		if (error == ERRCODE0)
			write(STDERR_FILENO, ERR_MSG0, ft_strlen(ERR_MSG0));
	else if (!error && strerror)
		write(STDERR_FILENO, strerror, ft_strlen(strerror));
	else if (!error && !strerror)
		perror("Error! ");
	exit(EXIT_FAILURE);
}

int	exit_tutorial(t_map *mapdata)
{
	if (mapdata)
	{
		mlx_destroy_window (mapdata->mlx, mapdata->mlx_win);
		mlx_destroy_image (mapdata->mlx, mapdata->img);
	}
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

float	ft_module(float x, float y)
{
	float		len;

	len = sqrt((x * x) + (y * y));
	return (len);
}
