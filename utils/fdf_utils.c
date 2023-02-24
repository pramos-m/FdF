/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:31:28 by pramos-m          #+#    #+#             */
/*   Updated: 2023/02/24 13:50:45 by pramos-m         ###   ########.fr       */
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
	else if (error == ERRCODE4)
		write(STDERR_FILENO, ERR_MSG4, ft_strlen(ERR_MSG4));
	exit(EXIT_FAILURE);
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
