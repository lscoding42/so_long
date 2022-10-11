/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 23:10:15 by lhafsi            #+#    #+#             */
/*   Updated: 2022/10/12 00:12:23 by lhafsi           ###   ########.fr       */
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
	// //test
	printf("\npremier print\n");
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	i = 0;
	// //fin du test
	map[data->pos[0]][data->pos[1]] = '*';
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '*')
				cp_mod += transform(data, map, i, j);			
			j++;
		}
		i++;
	}
	printf("\nmod :%d\n", mod);
	printf("\ncpmod :%d\n", cp_mod);
	//test print
	printf("\n 2e print\n\n");
	i = 0;
	j = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	// //fin du test
	printf("COMPTEUR : %i // NB DEPART : %i\n", data->cpt_c, data->nb_c);
	if (mod != cp_mod && data->cpt_c != data->nb_c)
			algo_path_finding(data, map, cp_mod);
	// ft_double_free(c);
	printf("2-- COMPTEUR : %i // NB DEPART : %i\n", data->cpt_c, data->nb_c);
	if (data->cpt_c == data->nb_c && data->cpt_e > 0)
		return (1);
	return (0);
}

// int	algo_path_finding(t_data *data, char **map, int mod)
// {
// 	int	i;
// 	int	j;
// 	int	cp_mod;

// 	i = 1;
// 	cp_mod = mod;
// 	map[data->pos[0]][data->pos[1]] = '*';
// 	while (map[i])
// 	{
// 		j = 1;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == '*')
// 				cp_mod += transform(data, map, i, j);
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (mod != cp_mod && !(data->cpt_c == data->nb_c))
// 		if (!(data->cpt_e))
// 			algo_path_finding(data, map, cp_mod);
// 	//ft_double_free(c);
// 	if (data->cpt_c == data->nb_c && data->cpt_e > 0)
// 		return (1);
// 	return (0);
// }

int	check_path(char **map)
{
	t_data	data;
	char	**cpy;

	if (!map || !map[0])
		return (0);
	data.nb_c = ft_count_c(map, 'C');
	data.cpt_e = 0;
	data.cpt_c = 0;
	pos_player(&data, map);
	cpy = ft_strddup((const char **)map);
	return (algo_path_finding(&data, cpy, 0));
}

// 0 - check array size
// 1 - check chaque array -> flag les positions possibles
// 2 - check compteurs : si complets : done sinon next
// 3 - next array -> check positions non flag et possibles

// int	check_path(char **map)
// {
// 	if (!map || !map[0])
// 		return (0);
// 	if (!path_checker(map))
// 		return(0);
// 	return (1);
// }


// void	malloc_arr(char *array, int size)
// {
// 	t_tab	malloc_array;

// 	array = malloc(sizeof(char) * size + 1);
// 	if (!array)
// 		return (NULL);
// 	return (array);
// }


// int	algo_path_finding(t_data *data, char **map, int mod)
// {
// 	int i;
// 	int j;
// 	int	cp_mod;

// 	i = 1;
// 	cp_mod = mod;
// 	// //test
// 	// while (map[i])
// 	// {
// 	// 	printf("%s\n", map[i]);
// 	// 	i++;
// 	// }
// 	// i = 1;
// 	// printf("\n\n");
// 	// //fin du test
// 	map[data->pos[0]][data->pos[1]] = '*';
// 	while (map[i])
// 	{
// 		j = 1;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == '*')
// 				cp_mod += transform(data, map, i, j);			
// 			j++;
// 		}
// 		i++;
// 	}
// 	// printf("mod :%d\n", mod);
// 	// printf("cpmod :%d\n", cp_mod);
// 	// //test print
// 	// i = 0;
// 	// j = 0;
// 	// while (map[i])
// 	// {
// 	// 	printf("%s\n", map[i]);
// 	// 	i++;
// 	// }
// 	// printf("\n\n");
// 	// //fin du test
// 	if (mod != cp_mod && (!(data->cpt_c == data->nb_c && data->cpt_e)))
// 	{
// 				algo_path_finding(data, map, cp_mod);
// 		// printf("pouet\n");
// 	}
// 	// ft_double_free(c);
// 	if (data->cpt_c == data->nb_c && data->cpt_e > 0)
// 		return (1);
// 	return (0);
// }