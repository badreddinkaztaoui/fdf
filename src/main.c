/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:02:56 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/07/31 08:12:06 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_putpixel(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x
			* (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	initialize(t_window *win, t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->matrice = NULL;
	win->win_w = 800;
	win->win_h = 800;
}

void	ft_init_map(t_window *win)
{
	t_image		img;

	win->mlx = mlx_init();
	img.img = mlx_new_image(win->mlx, win->win_w, win->win_h);
	win->mlx_win = mlx_new_window(win->mlx, win->win_w, win->win_h, "fdf");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	mlx_put_image_to_window(win->mlx, win->mlx_win, img.img, 0, 0);
}

int	main(int ac, char **av)
{
	t_window	win;
	t_map		map;
	int			fd;

	if (ac != 2)
		ft_error("Please enter one argument. No more, no less.");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error("Can't read from this file.");
	initialize(&win, &map);
	read_map(fd, &map);
	ft_init_map(&win);
	mlx_loop(win.mlx);
	return (0);
}
