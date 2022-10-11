/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 03:54:20 by lhafsi            #+#    #+#             */
/*   Updated: 2022/09/30 23:28:20 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#include <stdio.h>
#include <errno.h>

int	img_init(t_cub *cub)
{
//// LIVE IMG INIT
	cub->live.img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->live.addr = mlx_get_data_addr(cub->live.img, &cub->live.bpp, &cub->live.line_length, &cub->live.endian);
//// BACKGROUND INIT
	cub->back.img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->back.addr = mlx_get_data_addr(cub->back.img, &cub->back.bpp, &cub->back.line_length, &cub->back.endian);
	return (0);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	int		ret; 
	t_cub	cub;

	if (ac != 2 || !av[1])
		return (ft_putstr_fd("Error\nInput incorrect", 2), 0);
	if (ft_file_name(av[1]) == 0)
		return (ft_putstr_fd("Error\nInput incorrect", 2), 0);
	ret = ft_manage_gnl(av[1]);
	if (ret == -1)
		return (0);
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, WIDTH, HEIGHT, "so_long");
	
	img_init(&cub);
	
	cub.tex.img = mlx_xpm_file_to_image(cub.mlx, "xpm/perso.xpm", &cub.width, &cub.height);
	//printf("%s\n", strerror(errno));
	cub.tex.addr = mlx_get_data_addr(cub.tex.img, &cub.tex.bpp, &cub.tex.line_length, &cub.tex.endian);

	// mlx_hook(cub.win, 2, 1L<<0, keypress_event, &cub);
	// mlx_hook(cub.win, 17, 1L<<17, destroy_event, &cub);
	mlx_loop_hook(cub.mlx, render, &cub);
	mlx_loop(cub.mlx);

	//clear_project(&cub);
	return (0);
}
