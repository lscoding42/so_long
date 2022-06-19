/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhafsi <lhafsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 03:54:20 by lhafsi            #+#    #+#             */
/*   Updated: 2022/06/19 20:51:51 by lhafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx_linux/mlx.h"
#include <math.h>

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + ((y * data->line_length) + (x * 4));
	*(unsigned int*)dst = color;
}

// int	pixel_color()
// {
// 	return (color)
// }


// void	draw_tile(t_img *img, int x, int y, t_img *tex)
// {
// 	int	i;
// 	int	j;
	
// 	i = 0;//i represente y et j represente x
// 	while()
// 	{
// 		j = 0;
// 		while ()
// 		{
// 			my_mlx_pixel_put()
// 			j++;
// 		}
// 		i++;	
// 	}
// }

void	ft_line(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			my_mlx_pixel_put(img, i, j, 0x54c7896 + j * (i * 100));
			j += 1;
		}
		i += 1;
	}
	// while (i < 249)
	// {
	// 	j = 0;
	// 	while (j < 500)
	// 	{
	// 		my_mlx_pixel_put(img, j, i, 0x886666FF + j);
	// 		j++;
	// 	}
	// 	i += 1;
	// }
	// j = 0;
	// while (i < 500)
	// {
	// 	j = 0;
	// 	while (j < 250)
	// 	{
	// 		my_mlx_pixel_put(img, j, i, 0x3485bb2 + j);
	// 		j += 25;
	// 	}
	// 	while (j < 500)
	// 	{
	// 		my_mlx_pixel_put(img, j, i, 0x00FFFFF);
	// 		j += 25;
	// 	}
	// 	i += 1;
	// }
	
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	ft_line(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}