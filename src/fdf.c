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

	if (ac != 2)
		ft_error_handler(0, "Error! Invalid parameters given!\n"); 
	ft_check_map(av[1], &mapdata);
	ft_fill_pixels(&mapdata);
	printf("Fill pixels: OK\n");
	ft_window_create(&mapdata);
	printf("Window create: OK\n");
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
	printf("ENTRA: OK\n");
	mapdata->mlx = mlx_init(); //devuelve un void * con la direccion de memoria donde se encuentra la ventana
	printf("INIT: OK\n");
	mapdata->mlx_win = mlx_new_window(mapdata->mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!"); //Creamos la ventana a partir de la direccion de memoria de donde "empieza" la ventana
	printf("NEW WIN: OK\n");
	mapdata->img = mlx_new_image(mapdata->mlx, WIN_WIDTH, WIN_HEIGHT);
	printf("NEW IMG: OK\n");
	mapdata->addr = mlx_get_data_addr(mapdata->img, &mapdata->bits_per_pixel, &mapdata->line_length,
			&mapdata->endian);//Asigna valor a los parametros mandados en base a la img que le mandas. Img no le mandas direccion ya que ya tiene valor, las demas si para que se puedan editar.  img.line_length(es el "width")  img.bits_per_pixel(cantidad de bits para rellenar un pixel) img.endian(devuelve 0 o 1, estableciendo el orden de los bits para saber si estan de derecha a izquierda o al reves en orden de prioridad)
	printf("ADDR: OK\n");
	mlx_put_image_to_window(mapdata->mlx, mapdata->mlx_win, mapdata->img, 0, 0);
}

void	my_mlx_pixel_put(t_map *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));//Dst va a ser la direccion de memoria del primer pixel a imprimir. sumado de y * la length, y sumado por x * bytes (porque la direccion de x, no es 1, 2, 3, 4. Si no que cada posicion es la primera x los bytes que sean cada pixel (dividimos los bits y los onvertimos en bytes pq es un char *)).
	*(unsigned int*)dst = color;
}

int	exit_tutorial(t_map *window)
{
	if (window)
		mlx_destroy_window (window->mlx, window->mlx_win);
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