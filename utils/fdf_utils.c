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

void	ft_error_handler(int error, char *strerror)
{
	if (!strerror && error)
	{
		if (error == ERRCODE0)
			write(STDERR_FILENO, ERR_MSG0, ft_strlen(ERR_MSG0));
	}
	else if (!error && strerror)
		write(STDERR_FILENO, strerror, ft_strlen(strerror));
	else if (!error && !strerror)
		perror("Error! ");
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
