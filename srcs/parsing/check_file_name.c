/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:00:20 by lhafsi            #+#    #+#             */
/*   Updated: 2022/10/03 23:31:40 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_find_dot(char *av)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	while (av[i] && av[i] != '.')
		i++;
	return (i);
}

int	ft_file_name(char *av)
{
	int	i;
	int	size;

	if (av[0] == '.')
		return (0);
	i = ft_find_dot(av) + 1;
	size = 0;
	while (av[i])
	{
		size++;
		i++;
	}
	if (size != 3)
		return (0);
	i = ft_find_dot(av) + 1;
	if (av[i] != 'b' && av[i + 1] != 'e' && av[i + 2] != 'r')
		return (0);
	return (1);
}
