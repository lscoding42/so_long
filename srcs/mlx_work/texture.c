/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:26:18 by lhafsi            #+#    #+#             */
/*   Updated: 2022/10/14 12:12:22 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

unsigned int	get_color(t_data *data, int x, int y)
{
	char			*dst;
	unsigned int	color;

	dst = data->img.addr + (y * data->map.width + x * 4);
	color = *(unsigned int*)dst;
	return (color);
}

void	put_color(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->map.width + x * 4);
	*(unsigned int*)dst = color;
}

// void	draw_background(t_data *data)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	while (i < HEIGHT)
// 	{
// 		j = 0;
// 		while (j < WIDTH)
// 		{
// 			put_color(&data->img, j, i, 0x00FF0000);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	draw_tex(t_data *data, int x_offset, int y_offset)
{
	size_t	i;
	size_t	j;
	int	color;
/*	float	x_ratio;
	float	y_ratio;

	x_ratio = data->width / SLOT_WIDTH;
	y_ratio = data->height / SLOT_HEIGHT;*/
	i = 0;
	while (i < (size_t)data->map.height)
	{
		j = 0;
		while (j < (size_t)data->map.width)
		{
			color = get_color(&data->tex, j, i);
			if (color != 0x0)
				put_color(&data->back, j + x_offset, i + y_offset, color);
			j++;
		}
		i++;
	}
}