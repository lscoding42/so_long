/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 23:10:15 by lhafsi            #+#    #+#             */
/*   Updated: 2022/10/20 00:31:14 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include<stdio.h>

int	algo_path_finding(t_data *data, char **map, int mod)
{
	int i;
	int j;
	int	cp_mod;

	i = 0;
	cp_mod = mod;
	map[data->player.y][data->player.x] = '*';
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '*')
				cp_mod += transform(data, map, j, i);			
			j++;
		}
		i++;
	}
	// i = 0;
	// while (map[i])
	// {
	// 	printf("%s\n", map[i]);
	// 	i++;
	// }
	printf("\n");
	if (mod != cp_mod && data->map.cpt_c <= data->map.nb_c)
			algo_path_finding(data, map, cp_mod);
	// printf("coooooooooooooooooooooogitooooooooooooooooooooooo\n\n\n\\n\n\n\n\n\n\n\n\n\n\n\n\nqweqweqweqwe");
	if (data->map.cpt_c == data->map.nb_c && data->map.cpt_e > 0)
		return (1);
	return (0);
}

int	check_path(char **map)
{
	t_data	data;
	char	**cpy;

	if (!map || !map[0])
		return (0);
	data.map.nb_c = ft_count_c(map, 'C');
	data.map.cpt_e = 0;
	data.map.cpt_c = 0;
	pos_player(&data, map);
	cpy = ft_strddup((const char **)map);
	if (algo_path_finding(&data, cpy, 0))
		return (free_tab(cpy), 1);
	return (free_tab(cpy), 0);
}
