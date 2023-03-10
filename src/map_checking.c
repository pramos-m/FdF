/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:41:16 by pramos-m          #+#    #+#             */
/*   Updated: 2023/03/09 16:43:29 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#define BUFFER_TAMAÑO 500000

int	ft_read_check(int *fd, t_map *mapdata)
{
	char	buffer[BUFFER_TAMAÑO + 1];
	int		bytes_read;

	buffer[0] = '\0';
	bytes_read = read(*fd, buffer, BUFFER_TAMAÑO);
	if (bytes_read == -1)
		return (0);
	mapdata->content = ft_strdup("");
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		free(mapdata->content);
		mapdata->content = ft_strjoin(mapdata->content, buffer);
		ft_bzero(buffer, BUFFER_TAMAÑO + 1);
		bytes_read = read(*fd, buffer, BUFFER_TAMAÑO);
	}
	return (1);
}

int	ft_check_content(int x, int y, t_map *mapdata)
{
	static char	**bits = NULL;

	mapdata->columns = ft_split(mapdata->content, '\n');
	if (!mapdata->columns)
	 	return (0);
	while (mapdata->columns[++y])
	{
		ft_free_matrix(bits);
		bits = ft_split(mapdata->columns[y], ' ');
		if (!ft_check_bits(bits))
			return (0);
		if (!ft_line_len(bits))
			return (0);

	}
	x =  ft_line_len(bits);
	mapdata->width = x;
	mapdata->height = y;
	mapdata->size = x * y;
	ft_free_matrix(mapdata->columns);
	ft_free_matrix(bits);
	return (1);
}

int	ft_check_bits(char **bits)
{
	int		i;
	char	**hex;

	i = -1;
	while (bits[++i])
	{
		if (ft_strchr(bits[i], ','))
		{
			hex = ft_split(bits[i], ',');
			if (!hex)
				return (0);
			if (ft_matrixlen(hex) > 2 || !ft_isnum(hex[0]) || !ft_isint(hex[0]) || ft_check_hexa(hex[1]))
				return (0);
			ft_free_matrix(hex);
		}
	}
	return (i);
}

int	ft_check_hexa(char *str)
{
	int	i;

	i = 1;
	if (!str)
		return (0);
	if (str[0] != '0')
		return (0);
	while (str[i])
		if (!ft_strchr(BU16, str[i]) || !ft_strchr(BL16, str[i]))
			return (0);
	return (1);
}
