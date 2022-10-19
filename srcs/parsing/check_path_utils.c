/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 23:10:15 by lhafsi            #+#    #+#             */
/*   Updated: 2022/10/14 11:41:16 by lhafsi           ###   ########.fr       */
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

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				data->player.x = x;
				data->player.y = y;
			}
			y++;
		}
		x++;
	}
}

int	put_star(t_data *data, char **map, int x, int y)
{
	if (map[x][y] && map[x][y] == 'C')
		data->map.cpt_c++;
	if (map[x][y] && map[x][y] == 'E')
		data->map.cpt_e++;
	map[x][y] = '*';
	return (1);
}

int	transform(t_data *data, char **map, int x, int y)
{
	int	i;

	i = 0;
	if (can_transform(map[x][y + 1]))
		i += put_star(data, map, x, y + 1);
	if (can_transform(map[x + 1][y]))
		i += put_star(data, map, x + 1, y);
	if (can_transform(map[x - 1][y]))
		i += put_star(data, map, x - 1, y);
	if (can_transform(map[x][y - 1]))
		i += put_star(data, map, x, y - 1);
	return (i);
}
