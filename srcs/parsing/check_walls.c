/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:13:47 by lhafsi            #+#    #+#             */
/*   Updated: 2022/10/04 01:21:47 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_check_rectangle(char **map)
{
	int	i;

	i = 1;
	if(!map)
		return (0);
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_line_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{	
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_hor_walls(char **map)
{
	int	i;
	int	last;

	i = 0;
	last = ft_dstrlen((const char **)map) - 1;
	while (map[i])
	{	
		if (i == 0 && !ft_check_line_wall(map[0]))
			return (0);
		else if (i == last && !ft_check_line_wall(map[last]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_mid_wall(char *line)
{
	int	i;
	int	j;

	j = ft_strlen(line);
	if (line[0] != '1')
		return (0);
	i = 1;
	while (line[i] && i < j - 1)
		i++;
	if (line[i] != '1')
		return (0);
	return (1);
}

int	ft_check_ver_wall(char **map)
{
	int	i;

	i = 1;
	while (map[i] && i < ft_dstrlen((const char **)map) - 1)
	{
		if (ft_check_mid_wall(map[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
