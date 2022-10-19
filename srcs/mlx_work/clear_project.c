/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_project.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:26:25 by lhafsi            #+#    #+#             */
/*   Updated: 2022/10/19 22:56:48 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	clear_project(t_data *data)
{
	//mlx_destroy_image(data->mlx, data->tex.img);
	//mlx_destroy_image(cub->mlx, cub->img.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

int	destroy_event(t_data *data)
{
	clear_project(data);
	exit(0);
}
