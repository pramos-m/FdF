/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:44:25 by pramos-m          #+#    #+#             */
/*   Updated: 2023/02/24 11:56:40 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int ac, char **av)
{
	t_map	mapdata;

	(void)av;
	if (ac != 2)
		ft_error_handler(0, "Error! Invalid parameters given!\n"); 
	ft_check_map(av[1], &mapdata);
	ft_fill_pixels(&mapdata);
	ft_window_create(&mapdata);
	ft_print_win(&mapdata);
	mlx_hook(mapdata.mlx_win, 17, 0, exit_tutorial, &mapdata);
	mlx_hook(mapdata.mlx_win, 2, 0, read_keys, &mapdata);
	mlx_loop(mapdata.mlx);
	return (0);
}

void ft_check_map(char *route, t_map *mapdata)
{
	int		fd;

	if (ft_strrncmp(route, ".fdf", 4))
		ft_error_handler(0, "Error! Invalid File extension!\n");
	fd = open(route, O_RDONLY);
	if (fd == -1)
		ft_error_handler(0, NULL); 
	if (!ft_read_check(&fd, mapdata))
		ft_error_handler(0, NULL);
	if (close(fd) == -1)
		ft_error_handler(0, NULL);
	if (!ft_check_content(0, -1, mapdata))
		ft_error_handler(0, "Error! Invalid File Content!\n");
}

void	ft_window_create(t_map	*mapdata)
{
	mapdata->mlx = mlx_init(); //devuelve un void * con la direccion de memoria donde se encuentra la ventana
	mapdata->mlx_win = mlx_new_window(mapdata->mlx, WIN_WIDTH, WIN_HEIGHT, "Pol Ramos FDF"); //Creamos la ventana a partir de la direccion de memoria de donde "empieza" la ventana
	mapdata->img = mlx_new_image(mapdata->mlx, WIN_WIDTH, WIN_HEIGHT);
	mapdata->addr = mlx_get_data_addr(mapdata->img, &mapdata->bits_per_pixel, &mapdata->line_length,
			&mapdata->endian);//Asigna valor a los parametros mandados en base a la img que le mandas. Img no le mandas direccion ya que ya tiene valor, las demas si para que se puedan editar.  img.line_length(es el "width")  img.bits_per_pixel(cantidad de bits para rellenar un pixel) img.endian(devuelve 0 o 1, estableciendo el orden de los bits para saber si estan de derecha a izquierda o al reves en orden de prioridad)
}

void	ft_print_win(t_map	*mapdata)
{
	ft_print_wallpaper(mapdata);
	ft_escale(mapdata);
	ft_traslate(mapdata);
	ft_print_map(mapdata);
	mlx_put_image_to_window(mapdata->mlx, mapdata->mlx_win, mapdata->img, 0, 0);
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
	int	i;
	int	scale;

	i = -1;
	scale = WIN_HEIGHT / ft_module(WIN_WIDTH, WIN_HEIGHT);
	while (++i < mapdata->size)
	{
		mapdata->pixels[i].x = mapdata->pixels[i].x * scale;
		mapdata->pixels[i].y = mapdata->pixels[i].y * scale;
	}
}

int	ft_module(int x, int y)
{
	t_pixel	vector;
	float		len;

	vector.x = x - x;
	vector.y = y - y;
	len = sqrt((vector.x * vector.x) + (vector.y * vector.y));
}

void ft_print_map(t_map	*mapdata)
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
			// my_mlx_pixel_put(mapdata, mapdata->pixels[p].x, mapdata->pixels[p].y, mapdata->pixels[p].color);
			if (p + 1 < mapdata->size && mapdata->pixels[p].y == mapdata->pixels[p + 1].y)
				ft_print_line(mapdata, mapdata->pixels[p], mapdata->pixels[p + 1]);
			if (p + mapdata->width < mapdata->size)
				ft_print_line(mapdata, mapdata->pixels[p], mapdata->pixels[p + mapdata->width]);
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
	float		len;

	vector.x = b.x - a.x;
	vector.y = b.y - a.y;
	len = sqrt((vector.x * vector.x) + (vector.y * vector.y));
	increment.x = vector.x / len;
	increment.y = vector.y / len;
	toprint.x = a.x;
	toprint.y = a.y;
	while (len-- > 0)
	{
		my_mlx_pixel_put(mapdata, toprint.x, toprint.y, a.color);
		toprint.x += increment.x;
		toprint.y += increment.y;
	}
	
}
