/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:26:25 by lhafsi            #+#    #+#             */
/*   Updated: 2022/10/14 12:06:24 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// int	is_wall(t_data *data, int x, int y)
// {
// 	if (data->map[x][y] != '1')
// 		return (1);
// 	return (0);
// }

int keypress_event(int key, t_data *data)
{
	if (key == 65307)
		destroy_event(data);
	// if (key == HAUT && is_wall(data->map, (data->pos[0]) - 1,data->pos[1]))
	// 	;
	// if (key == BAS && is_wall(data->map, (data->pos[0]) + 1,data->pos[1]))
	// 	;
	// if (key == GAUCHE && is_wall(data->map, data->pos[0],(data->pos[1]) + 1))
	// 	;
	// if (key == DROITE && is_wall(data->map, data->pos[0],(data->pos[1]) - 1))
	// 	;
	return (0);
}
