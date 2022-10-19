/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:13:47 by lhafsi            #+#    #+#             */
/*   Updated: 2022/10/14 12:07:32 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "../mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "defines.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

/****************************************************************************/
/******************              STRUCTS               **********************/
/****************************************************************************/

typedef struct	s_img {
	void	*pic;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_player {
	int		x;
	int		y;
}				t_player;

typedef struct	s_map {
	char	**tab;
	int		width;
	int		height;
	int		nb_c;
	int		cpt_c;
	int		cpt_e;
}				t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	
	t_img		live;
	t_img		back;
	t_img		img;
	t_img		tex;
	
	t_player	player;
	
	t_map		map;
}				t_data;

/****************************************************************************/
/******************           SRCS > PARSING           **********************/
/****************************************************************************/

// SRCS > PARSING > FILE_NAME.C
int		ft_find_dot(char *av);
int		ft_file_name(char *av);

// SRCS > PARSING > MAP_TO_ARRAY.C
void	ft_double_free(char *s1, char *s2);
char	*ft_map_to_str(int fd);
char	**ft_create_map(char *str);
int		ft_is_map_valid(char **map);
int		ft_manage_gnl(char *map);

// SRCS > PARSING > CHECK_WALLS.C
int		ft_check_rectangle(char **map);
int		ft_check_line_wall(char *line);
int		ft_check_hor_walls(char **map);
int		ft_check_mid_wall(char *line);
int		ft_check_ver_wall(char **map);

// SRCS > PARSING > CHECK_MID.C
int		ft_check_c(char *line);
int		ft_count_c(char **map, char c);
int		ft_count_cep(char **map);
int		ft_check_mid_c(char **map);

// SRCS > PARSING > CHECK_PATH_UTILS.C
int		can_transform(char c);
void	pos_player(t_data *data, char **map);
int		put_star(t_data *data, char **map, int x, int y);
int		transform(t_data *data, char **map, int x, int y);

// SRCS > PARSING > CHECK_PATH.C
int		algo_path_finding(t_data *data, char **map, int mod);
int		check_path(char **map);

// SRCS > PARSING > MANAGE_ERRORS.C
int		ft_display_errors(char **map);


/****************************************************************************/
/******************          SRCS > MLX_WORK           **********************/
/****************************************************************************/

// SRCS > MLX_WORK > INIT_PROJECT.C
void	init_project(t_data *data);
int		img_init(t_data *data);
int		keypress_event(int key, t_data *data);

// SRCS > MLX_WORK > OTHER.C
int		render(t_data *data);

// SRCS > MLX_WORK > MANAGE_KEYS.C
int	is_wall(t_data *data);

// SRCS > MLX_WORK > TEXTURE.C
unsigned int	get_color(t_data *data, int x, int y);
void	put_color(t_data *data, int x, int y, int color);
void	draw_background(t_data *data);
void	draw_tex(t_data *data, int x_offset, int y_offset);

// SRCS > MLX_WORK > CLEAR_PROJECT.C
void	clear_project(t_data *data);
int		destroy_event(t_data *data);
#endif