/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 23:10:15 by lhafsi            #+#    #+#             */
/*   Updated: 2022/10/19 23:44:35 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	can_transform(char c)
{
	if (c == 'E' || c == 'P' || c == '0' || c == 'C')
		return (1);
	return (0);
}

void	pos_player(t_data *data, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				data->player.x = x;
				data->player.y = y;
			}
			x++;
		}
		y++;
	}
}

int	put_star(t_data *data, char **map, int x, int y)
{
	if (map[y][x] && map[y][x] == 'C')
		data->map.cpt_c++;
	if (map[y][x] && map[y][x] == 'E')
		data->map.cpt_e++;
	map[y][x] = '*';
	return (1);
}

int	transform(t_data *data, char **map, int x, int y)
{
	int	i;

	i = 0;
	if (can_transform(map[y][x + 1]))
		i += put_star(data, map, x + 1, y);
	if (can_transform(map[y + 1][x]))
		i += put_star(data, map, x, y + 1);
	if (can_transform(map[y - 1][x]))
		i += put_star(data, map, x, y - 1);
	if (can_transform(map[y][x - 1]))
		i += put_star(data, map, x - 1, y);
	return (i);
}
