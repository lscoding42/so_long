/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:49:14 by lhafsi            #+#    #+#             */
/*   Updated: 2022/10/04 02:41:30 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_display_errors(char **map)
{
	if (!ft_check_rectangle(map))
		return (ft_putstr_fd("Error\nMap error: Not a rectangle", 2), 0);
	if (ft_count_cep(map) == 2)
		return (ft_putstr_fd("Error\nMap error: No collectibles", 2), 0);
	if (ft_count_cep(map) == 3)
		return (ft_putstr_fd("Error\nMap error: Check exit - E", 2), 0);
	if (ft_count_cep(map) == 4)
		return (ft_putstr_fd("Error\nMap error: Check position - P", 2), 0);
	if (!ft_check_hor_walls(map))
		return (ft_putstr_fd("Error\nMap error: Horizontal walls", 2), 0);
	if (!ft_check_ver_wall(map))
		return (ft_putstr_fd("Error\nMap error: Vertical walls", 2), 0);
	if (!ft_check_mid_c(map))
		return (ft_putstr_fd("Error\nMap error: Unauthorized char", 2), 0);
	if (!check_path(map))
	 	return (ft_putstr_fd("Error\nMap error: No valid path", 2), 0);
	return (1);
}

// typedef struct s_test
// {
// 	(int *)fct(char **map);
// 	char *msg;
	
// }t_test;

// t_test test[8];

// test[0]= 