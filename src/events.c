/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 02:14:12 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/08/07 05:11:56 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	onclose(t_fdf *fdf)
{
	mlx_destroy_window(fdf->win.mlx, fdf->win.mlx_win);
	exit(0);
}

void	translate(int key, t_fdf *fdf)
{
	if (key == 100)
		fdf->trans.t_x += 10;
	if (key == 97)
		fdf->trans.t_x -= 10;
	if (key == 119)
		fdf->trans.t_y -= 10;
	if (key == 115)
		fdf->trans.t_y += 10;
}

void	scale(int key, t_fdf *fdf)
{
	if (key == 65451)
		fdf->trans.scale += 1;
	if (key == 65453)
		fdf->trans.scale -= 1;
}

int	onmousemove(int key, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (key == 4)
		fdf->trans.zoom += 2;
	if (key == 5)
		fdf->trans.zoom -= 2;
	mlx_destroy_image(fdf->win.mlx, fdf->img.img);
	mlx_clear_window(fdf->win.mlx, fdf->win.mlx_win);
	draw_map(fdf);
	return (0);
}

int	onkeypress(int key, t_fdf *fdf)
{
	if (key == 65307)
		onclose(fdf);
	translate(key, fdf);
	scale(key, fdf);
	mlx_destroy_image(fdf->win.mlx, fdf->img.img);
	mlx_clear_window(fdf->win.mlx, fdf->win.mlx_win);
	draw_map(fdf);
	return (0);
}
