/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:26:06 by lhafsi            #+#    #+#             */
/*   Updated: 2022/08/24 15:20:51 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	map_tiles(t_cub *cub)
{
	draw_tex(cub, WIDTH / 2 - cub->width / 2, HEIGHT / 2 - cub->height / 2);
	return (0);
}

// int	map_update(t_cub *cub)
// {
	
// 	return (0);
// }

// int	render_background(t_cub *cub)
// {
// 	draw_background(cub);
// 	draw_tex(cub, WIDTH / 2 - cub->width / 2, HEIGHT / 2 - cub->height / 2);
// 	mlx_put_image_to_window(cub->mlx, cub->win, cub->back.img, 0, 0);
// 	return (0);
// }

int	render(t_cub *cub) // update
{
	draw_tex(cub, WIDTH / 2 - cub->width / 2, HEIGHT / 2 - cub->height / 2);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->back.img, 0, 0);
	return (0);
}
