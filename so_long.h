#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx_linux/mlx.h"

typedef	struct s_mlx
{
	void	*init;
	void	*win;
	void	*img;
	int		w;
	int		h;
}		t_mlx;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;



// MAIN.C


#endif