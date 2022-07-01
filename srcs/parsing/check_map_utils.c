/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:13:47 by lhafsi            #+#    #+#             */
/*   Updated: 2022/07/01 17:03:50 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_check_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{	
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_mid(char *line)
{
	int	i;

	if (line[0] != '1')
		return (0);
	i = 1;
	while (line[i + 1])
	{	
		if (!(line[i] == 'C' || line[i] == 'P' || line[i] == 'E'
			|| line[i] == '0' || line[i] == '1'))
			return (0);
		printf("i = %i\nline[i] = %c\n", i, line[i]);
		i++;
	}
	if (line[i] != '1')
		return (0);
	return (1);
}

// int	ft_check_map(char **map)
// {
// 	int	i;
// 	int	last;
// 	int	line;
	
// 	line = ft_strlen(map[i]);
// 	last = ft_count_lines(line);
// 	while (map[i])
// 	{
// 		if (ft_strlen(map[i]) != line)
// 			return (0);
// 		if (ft_check_wall(map[0]) == 0 || ft_check_wall(map[last]) == 0)
// 			return (0);
// 		if (ft_check_mid(map[i]) == 1 && i != 0 && i != last)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

