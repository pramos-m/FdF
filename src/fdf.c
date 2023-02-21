/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:44:25 by pramos-m          #+#    #+#             */
/*   Updated: 2023/02/21 18:02:16 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#define BUFFER_TAMAÑO 500000

int	main(int ac, char **av)
{
	t_map	mapdata;

	if (ac != 2)
		ft_error_handler(ERRCODE1);
	else
		ft_check_map(av[1], &mapdata);
	return (0);
}

void ft_check_map(char *route, t_map *mapdata)
{
	int		fd;

	if (ft_strrncmp(route, ".fdf", 4))
		ft_error_handler(ERRCODE2);
	fd = open(route, O_RDONLY);
	if (fd == -1)
		ft_error_handler(ERRCODE3);
	if (!ft_read_check(&fd, mapdata))
		ft_error_handler(ERRCODE3);
	if (close(fd) == -1)
		ft_error_handler(ERRCODE3);
	if (!ft_check_content(mapdata))
		ft_error_handler(ERRCODE3);
}
// int	main(void)
// {
// 	t_data	img;

// 	img.mlx = mlx_init(); //devuelve un void * con la direccion de memoria donde se encuentra la ventana
// 	img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "Hello world!"); //Creamos la ventana a partir de la direccion de memoria de donde "empieza" la ventana
// 	img.img = mlx_new_image(img.mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 			&img.endian);//Asigna valor a los parametros mandados en base a la img que le mandas. Img no le mandas direccion ya que ya tiene valor, las demas si para que se puedan editar.  img.line_length(es el "width")  img.bits_per_pixel(cantidad de bits para rellenar un pixel) img.endian(devuelve 0 o 1, estableciendo el orden de los bits para saber si estan de derecha a izquierda o al reves en orden de prioridad)
// 	// mlx_key_hook(img.mlx_win, read_keys, &img);
// 	mlx_hook(img.mlx_win, 17, 0, exit_tutorial, &img);
// 	mlx_hook(img.mlx_win, 2, 0, read_keys, &img);
// 	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
// 	mlx_loop(img.mlx);
// 	return (0);
// }

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));//Dst va a ser la direccion de memoria del primer pixel a imprimir. sumado de y * la length, y sumado por x * bytes (porque la direccion de x, no es 1, 2, 3, 4. Si no que cada posicion es la primera x los bytes que sean cada pixel (dividimos los bits y los onvertimos en bytes pq es un char *)).
// 	*(unsigned int*)dst = color;
// }

// int	exit_tutorial(t_data *window)
// {
// 	if (window)
// 		mlx_destroy_window (window->mlx, window->mlx_win);
// 	exit(EXIT_SUCCESS);
// }

// int	read_keys(int key_pressed, void *param)
// {
// 	t_data	*img;

// 	img = (t_data *)param;
// 	if (key_pressed == ESC || !img)
// 		exit_tutorial(img);
// 	return (0);
// }
