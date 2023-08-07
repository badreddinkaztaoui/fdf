/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:02:56 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/08/07 04:57:02 by bkaztaou         ###   ########.fr       */
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

void	ft_init_vals(t_fdf *fdf)
{
	fdf->map.x = 0;
	fdf->map.y = 0;
	fdf->map.matrice = NULL;
	fdf->win.win_w = WINDOW_WIDTH;
	fdf->win.win_h = WINDOW_HEIGHT;
	fdf->trans.t_x = 0;
	fdf->trans.t_y = 0;
	fdf->trans.scale = 1;
	fdf->trans.zoom = 0;
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
	ft_init_vals(&fdf);
	fdf.win.mlx = mlx_init();
	fdf.win.mlx_win = mlx_new_window(fdf.win.mlx,
			fdf.win.win_w, fdf.win.win_h, WINDOW_NAME);
	read_map(fd, &fdf);
	draw_map(&fdf);
	mlx_hook(fdf.win.mlx_win, 17, 0, onclose, &fdf);
	mlx_key_hook(fdf.win.mlx_win, onkeypress, &fdf);
	mlx_mouse_hook(fdf.win.mlx_win, onmousemove, &fdf);
	mlx_loop(fdf.win.mlx);
	return (0);
}
