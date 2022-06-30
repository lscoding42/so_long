/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 03:54:20 by lhafsi            #+#    #+#             */
/*   Updated: 2022/06/30 15:19:22 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + ((y * data->line_length) + (x * 4));
// 	*(unsigned int*)dst = color;
// }

int	ft_count_lines(char *map)
{
	int		fd;
	int		count;
	char	*gnl;

	fd = open(map, O_RDONLY);
	if (fd > 0)
	{
		count = 0;
		gnl = get_next_line(fd);
		while (gnl != NULL)
		{ 
			count++;
			free (gnl);
			gnl = get_next_line(fd);
		}
		close (fd);
		free (gnl);
		return (count);
	}
	else
		write(1, "Error counting lines\n", 21);
	return (-1);
}

// int	main(int ac, char **av)
// {
// 	if (ac != 2)
// 		return 0;
// 	printf("LINES: %d\n", ft_count_lines(av[1]));
// 	// void	*mlx;
// 	// void	*mlx_win;
// 	// t_img	img;

// 	// mlx = mlx_init();
// 	// mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
// 	// img.img = mlx_new_image(mlx, 1000, 1000);
// 	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 	// 							&img.endian);
// 	// //my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	// ft_line(&img);
// 	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	// mlx_loop(mlx);
// }

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	if (ft_check_mid(av[1]) == 1)
		printf("line correct\n");
	else
		printf("Incorrect\n");
	return (0);
}