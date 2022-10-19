/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:13:47 by lhafsi            #+#    #+#             */
/*   Updated: 2022/10/04 02:22:59 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_check_c(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == 'C' || line[i] == 'P' || line[i] == 'E'
				|| line[i] == '0' || line[i] == '1'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_c(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	ft_count_cep(char **map)
{
	int	c;
	int	e;
	int	p;

	c = ft_count_c(map, 'C');
	e = ft_count_c(map, 'E');
	p = ft_count_c(map, 'P');
	if (c < 1)
		return (2);
	else if (e != 1)
		return (3);
	else if (p != 1)
		return (4);
	return (1);
}

int	ft_check_mid_c(char **map)
{
	int	i;

	i = 1;
	while (map[i] && i < ft_dstrlen((const char **) map) - 1)
	{
		if (ft_check_c(map[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
