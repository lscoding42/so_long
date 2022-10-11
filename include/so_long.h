/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:13:47 by lhafsi            #+#    #+#             */
/*   Updated: 2022/10/11 23:55:12 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "../mlx/mlx.h"
# include "../lib/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

#define WIDTH 800
#define HEIGHT 600

#define SLOT_WIDTH 100
#define SLOT_HEIGHT 100

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		pos[2];
	char	**map;
	int		nb_c;
	int		cpt_c;
	int		cpt_e;
}				t_data;

typedef struct s_cub
{
	void *mlx;
	void *win;
	t_data live;
	t_data back;

	t_data tex;
	int	width;
	int	height;
}	t_cub;

// SRCS
// SRCS > PARSING
// SRCS > PARSING > FILE_NAME.C
int	ft_find_dot(char *av);
int	ft_file_name(char *av);

// SRCS > PARSING > MAP_TO_ARRAY.C
void	ft_double_free(char *s1, char *s2);
char	*ft_map_to_str(int fd);
char	**ft_create_map(char *str);
int		ft_is_map_valid(char **map);
int		ft_manage_gnl(char *map);

// SRCS > PARSING > CHECK_WALLS.C
int	ft_check_rectangle(char **map);
int	ft_check_line_wall(char *line);
int	ft_check_hor_walls(char **map);
int	ft_check_mid_wall(char *line);
int	ft_check_ver_wall(char **map);

// SRCS > PARSING > CHECK_MID.C
int	ft_check_c(char *line);
int	ft_count_c(char **map, char c);
int	ft_count_cep(char **map);
int	ft_check_mid_c(char **map);

// SRCS > PARSING > CHECK_PATH_UTILS.C
int		can_transform(char c);
void	pos_player(t_data *data, char **map);
int		put_star(t_data *data, char **map, int x, int y);
int		transform(t_data *data, char **map, int x, int y);

// SRCS > PARSING > CHECK_PATH.C
int	algo_path_finding(t_data *data, char **map, int mod);
int	check_path(char **map);

// SRCS > PARSING > MANAGE_ERRORS.C
int	ft_display_errors(char **map);

// SRCS > MLX_WORK
// SRCS > MLX_WORK > FIRST.C
int so_long_launcher(void);
int	render(t_cub *cub);
int	keypress_event(int key, t_cub *cub);
int	destroy_event(t_cub *cub);
void	clear_project(t_cub *cub);

// SRCS > MLX_WORK > TEXTURE.C
unsigned int	get_color(t_data *data, int x, int y);
void	put_color(t_data *data, int x, int y, int color);
void	draw_background(t_cub *cub);
void	draw_tex(t_cub *cub, int x_offset, int y_offset);

#endif