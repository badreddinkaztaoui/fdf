/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 04:21:15 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/08/07 01:05:14 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_map(t_fdf *fdf)
{
	int	i;
	int	j;

	fdf->img.img = mlx_new_image(fdf->win.mlx, fdf->win.win_w, fdf->win.win_h);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	i = -1;
	while (++i < fdf->map.y)
	{
		j = -1;
		while (++j < fdf->map.x)
		{
			if (j + 1 < fdf->map.x)
				bresenhams(fdf, ft_init_pt(i, j, fdf, 'x'));
			if (i + 1 < fdf->map.y)
				bresenhams(fdf, ft_init_pt(i, j, fdf, 'y'));
		}
	}
	mlx_put_image_to_window(fdf->win.mlx, fdf->win.mlx_win, fdf->img.img, 0, 0);
}
