/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_project.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:26:25 by lhafsi            #+#    #+#             */
/*   Updated: 2022/10/14 09:53:40 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_project(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "so_long");
}

int	img_init(t_cub *cub)
{
//// LIVE IMG INIT
	cub->live.img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->live.addr = mlx_get_data_addr(cub->live.img, &cub->live.bpp,
		&cub->live.line_length, &cub->live.endian);
//// BACKGROUND INIT
	cub->back.img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->back.addr = mlx_get_data_addr(cub->back.img, &cub->back.bpp,
		&cub->back.line_length, &cub->back.endian);
	return (0);
}

// int so_long_launcher(void)
// {
// 	t_cub cub;

// 	cub.mlx = mlx_init();
// 	cub.win = mlx_new_window(cub.mlx, WIDTH, HEIGHT, "louisa");
// 	cub.img.img = mlx_new_image(cub.mlx, WIDTH, HEIGHT);
// 	cub.img.addr = mlx_get_data_addr(cub.img.img, &cub.img.bpp, &cub.img.line_length, &cub.img.endian);

// 	cub.tex.img = mlx_xpm_file_to_image(cub.mlx, "textures/toto.xpm", &cub.width, &cub.height);
// 	cub.tex.addr = mlx_get_data_addr(cub.tex.img, &cub.tex.bpp, &cub.tex.line_length, &cub.tex.endian);

// 	mlx_hook(cub.win, 2, 1L<<0, keypress_event, &cub);
// 	mlx_hook(cub.win, 17, 1L<<17, destroy_event, &cub);
// 	mlx_loop_hook(cub.mlx, render, &cub);
// 	mlx_loop(cub.mlx);

// 	// clear_project(&cub);
// 	return (0);
// }