/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 04:14:22 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/08/06 04:27:04 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	isometric(t_point *pt)
{
	pt->x0 = (pt->x0 - pt->y0) * cos(0.8);
	pt->y0 = (pt->x0 + pt->y0) * sin(0.8) - pt->z0;
	pt->x1 = (pt->x1 - pt->y1) * cos(0.8);
	pt->y1 = (pt->x1 + pt->y1) * sin(0.8) - pt->z1;
}

void	init_x(int i, int j, t_point *pt, t_fdf *fdf)
{
	pt->x0 = j * ZOOM;
	pt->x1 = (j + 1) * ZOOM;
	pt->y0 = i * ZOOM;
	pt->y1 = i * ZOOM;
	pt->z0 = fdf->map.matrice[i][j];
	pt->z1 = fdf->map.matrice[i][j + 1];
	if (pt->z0 || pt->z1)
		pt->color = 0xFF0000;
	else
		pt->color = 0xFFFFFF;
	isometric(pt);
	pt->x0 += 250;
	pt->x1 += 250;
	pt->y0 += 150;
	pt->y1 += 150;
}

void	init_y(int i, int j, t_point *pt, t_fdf *fdf)
{
	pt->x0 = j * ZOOM;
	pt->x1 = j * ZOOM;
	pt->y0 = i * ZOOM;
	pt->y1 = (i + 1) * ZOOM;
	pt->z0 = fdf->map.matrice[i][j];
	pt->z1 = fdf->map.matrice[i + 1][j];
	if (pt->z0 || pt->z1)
		pt->color = 0xFF0000;
	else
		pt->color = 0xFFFFFF;
	isometric(pt);
	pt->x0 += 250;
	pt->x1 += 250;
	pt->y0 += 150;
	pt->y1 += 150;
}

t_point	ft_init_pt(int i, int j, t_fdf *fdf, char dir)
{
	t_point	pt;

	if (dir == 'x')
		init_x(i, j, &pt, fdf);
	else
		init_y(i, j, &pt, fdf);
	pt.xinc = 0;
	pt.yinc = 0;
	return (pt);
}
