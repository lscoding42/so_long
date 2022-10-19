/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:26:06 by lhafsi            #+#    #+#             */
/*   Updated: 2022/10/19 22:58:35 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	map_tiles(t_data *data)
{
	draw_tex(data, WIDTH / 2 - data->map.width / 2, HEIGHT / 2 - data->map.height / 2);
	return (0);
}

// int	map_update(t_data *cub)
// {
	
// 	return (0);
// }

// int	render_background(t_data *cub)
// {
// 	draw_background(cub);
// 	draw_tex(cub, WIDTH / 2 - cub->width / 2, HEIGHT / 2 - cub->height / 2);
// 	mlx_put_image_to_window(cub->mlx, cub->win, cub->back.img, 0, 0);
// 	return (0);
// }

int	render(t_data *data) // update
{
	draw_tex(data, WIDTH / 2 - data->map.width / 2, HEIGHT / 2 - data->map.height / 2);
	mlx_put_image_to_window(data->mlx, data->win, data->back.pic, 0, 0);
	return (0);
}
