/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:00:20 by lhafsi            #+#    #+#             */
/*   Updated: 2022/10/14 04:19:33 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_double_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

char	*ft_map_to_str(int fd)
{
	char	*gnl;
	char	*str;
	char	*tmp;

	gnl = get_next_line(fd);
	str = malloc(sizeof(char) * (ft_strlen(gnl) + 1));
	if (!str)
		return (NULL);
	str[0] = '\0';
	while (gnl != NULL)
	{
		if (gnl[0] == '\n')
		{
			ft_double_free(gnl, str);
			ft_putendl_fd("Error\nGNL GONE ROGUE", 2);
			exit(1);
		}
		tmp = str;
		str = ft_strjoin(str, gnl);
		ft_double_free(gnl, tmp);
		gnl = get_next_line(fd);
	}
	return (free(gnl), str);
}

char	**ft_create_map(char *str)
{
	char	**map;
	int		i;

	i = 0;
	map = ft_split(str, '\n');
	if (!map || !map[0])
		return (0);
	if (map == NULL)
		return (0);
	return (map);
}

int	ft_is_map_valid(char **map)
{
	int		i;

	i = 0;
	if (!map || !map[0])
		return (0);
	if (!ft_display_errors(map))
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
		return (0);
	}
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (1);
}

#include <stdio.h>

int	ft_manage_gnl(char *av1)
{	
	int		fd;
	int		ret;
	char	*str;
	char	**map;

	ret = -1;
	fd = open(av1, O_RDONLY);
	if (fd < 0)
		return (-1);
	str = ft_map_to_str(fd);
	map = ft_create_map(str);
	if (fd > 0)
	{
		if (ft_is_map_valid(map))
			ret = 1;
		close(fd);
	}
	free(str);
	return (ret);
}

	// int i = 0;
	// while (s[i])
	// {
	// 	printf("hehe %s\n", s[i]);
	// 	i++;
	// }
	// exit(0);