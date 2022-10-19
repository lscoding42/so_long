/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_project.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:26:25 by lhafsi            #+#    #+#             */
/*   Updated: 2022/10/14 12:04:58 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_project(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "so_long");
}

int	img_init(t_data *data)
{
//// LIVE IMG INIT
	data->live.pic = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->live.addr = mlx_get_data_addr(data->live.pic, &data->live.bpp,
		&data->live.line_length, &data->live.endian);
//// BACKGROUND INIT
	data->back.pic = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->back.addr = mlx_get_data_addr(data->back.pic, &data->back.bpp,
		&data->back.line_length, &data->back.endian);
	return (0);
}
