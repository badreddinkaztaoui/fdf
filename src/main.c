/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:02:56 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/08/06 03:53:39 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_putpixel(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < fdf->win.win_w && y >= 0 && y < fdf->win.win_h)
	{
		dst = fdf->img.addr + (y * fdf->img.line_length + x
				* (fdf->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	ft_set_values(t_fdf *fdf)
{
	fdf->map.x = 0;
	fdf->map.y = 0;
	fdf->map.matrice = NULL;
	fdf->win.win_w = WINDOW_WIDTH;
	fdf->win.win_h = WINDOW_HEIGHT;
}

void	ft_set_map(int fd, t_fdf *fdf)
{
	fdf->win.mlx = mlx_init();
	fdf->img.img = mlx_new_image(fdf->win.mlx, fdf->win.win_w, fdf->win.win_h);
	fdf->win.mlx_win = mlx_new_window(fdf->win.mlx,
			fdf->win.win_w, fdf->win.win_h, WINDOW_NAME);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	read_map(fd, fdf);
	mlx_put_image_to_window(fdf->win.mlx, fdf->win.mlx_win, fdf->img.img, 0, 0);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;
	int		fd;

	if (ac != 2)
		ft_error("Please enter one argument. No more, no less.");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error("Can't read from this file.");
	ft_set_values(&fdf);
	ft_set_map(fd, &fdf);
	mlx_loop(fdf.win.mlx);
	return (0);
}
