/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:26:18 by lhafsi            #+#    #+#             */
/*   Updated: 2022/08/30 23:06:00 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

unsigned int	get_color(t_data *data, int x, int y)
{
	char			*dst;
	unsigned int	color;

	dst = data->addr + (y * data->line_length + x * 4);
	color = *(unsigned int*)dst;
	return (color);
}

void	put_color(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * 4);
	*(unsigned int*)dst = color;
}

// void	draw_background(t_cub *cub)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	while (i < HEIGHT)
// 	{
// 		j = 0;
// 		while (j < WIDTH)
// 		{
// 			put_color(&cub->img, j, i, 0x00FF0000);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	draw_tex(t_cub *cub, int x_offset, int y_offset)
{
	size_t	i;
	size_t	j;
	int	color;
/*	float	x_ratio;
	float	y_ratio;

	x_ratio = cub->width / SLOT_WIDTH;
	y_ratio = cub->height / SLOT_HEIGHT;*/
	i = 0;
	while (i < (size_t)cub->height)
	{
		j = 0;
		while (j < (size_t)cub->width)
		{
			color = get_color(&cub->tex, j, i);
			if (color != 0x0)
				put_color(&cub->back, j + x_offset, i + y_offset, color);
			j++;
		}
		i++;
	}
}