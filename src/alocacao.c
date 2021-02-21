/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alocacao.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:23:55 by cpereira          #+#    #+#             */
/*   Updated: 2021/02/16 10:51:43 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		get_imagepixel(t_data *data, int x, int y)
{
	char	*color;

	color = data->addr + (y * data->line_length + x *
		(data->bits_per_pixel / 8));
	return (*(unsigned int*)(color));
}

void	converte(unsigned char *c, unsigned int value, int size)
{
	int i;

	i = -1;
	while (++i < size)
		c[i] = (char)(value >> (i * 8));
}

void	check_n_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_array(void **array)
{
	unsigned	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}
