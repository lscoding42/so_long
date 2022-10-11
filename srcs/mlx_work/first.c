/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:26:25 by lhafsi            #+#    #+#             */
/*   Updated: 2022/08/24 10:26:26 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	clear_project(t_cub *cub)
{
	//mlx_destroy_image(cub->mlx, cub->tex.img);
	//mlx_destroy_image(cub->mlx, cub->img.img);
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	free(cub->mlx);
}

int	destroy_event(t_cub *cub)
{
	clear_project(cub);
	exit(0);
}

int keypress_event(int key, t_cub *cub)
{
	(void)cub;
	if (key == 65307)
		destroy_event(cub);
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