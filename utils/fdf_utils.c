/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:31:28 by pramos-m          #+#    #+#             */
/*   Updated: 2023/02/21 18:03:57 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_error_handler(int error)
{
	if (error == ERRCODE0)
		write(STDERR_FILENO, ERR_MSG0, ft_strlen(ERR_MSG0));
	else if (error == ERRCODE1)
		write(STDERR_FILENO, ERR_MSG1, ft_strlen(ERR_MSG1));
	else if (error == ERRCODE2)
		write(STDERR_FILENO, ERR_MSG2, ft_strlen(ERR_MSG2));
	else if (error == ERRCODE3)
		write(STDERR_FILENO, ERR_MSG3, ft_strlen(ERR_MSG3));
	exit(EXIT_FAILURE);
}

int	ft_line_len(char **bits)
{
	int			i;
	static int	x = 0;

	i = -1;
	while (bits[++i])
	{
		i++;
		printf("x: %d, i:%d\n", x, i);
	}
	if (x == 0)
		x = i;
	else{
		if (x != i)
		{
			printf("x: %d, i:%d", x, i);
			return (0);
		}
	}
	return (i);
}
