/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 04:14:22 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/08/07 07:48:40 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	isometric(t_point *pt, t_fdf *fdf)
{
	pt->x0 = (pt->x0 - pt->y0) * cos(0.9);
	pt->y0 = (pt->x0 + pt->y0)
		* sin(0.6) - (pt->z0 * fdf->trans.scale);
	pt->x1 = (pt->x1 - pt->y1) * cos(0.9);
	pt->y1 = (pt->x1 + pt->y1)
		* sin(0.6) - (pt->z1 * fdf->trans.scale);
}

void	init_x(int i, int j, t_point *pt, t_fdf *fdf)
{
	pt->x0 = j * (ZOOM + fdf->trans.zoom);
	pt->x1 = (j + 1) * (ZOOM + fdf->trans.zoom);
	pt->y0 = i * (ZOOM + fdf->trans.zoom);
	pt->y1 = i * (ZOOM + fdf->trans.zoom);
	pt->z0 = fdf->map.matrice[i][j];
	pt->z1 = fdf->map.matrice[i][j + 1];
	if (pt->z0 || pt->z1)
		pt->color = 0xFF0000;
	else
		pt->color = 0xFFFFFF;
	isometric(pt, fdf);
	pt->x0 += (250 + fdf->trans.t_x);
	pt->x1 += (250 + fdf->trans.t_x);
	pt->y0 += (150 + fdf->trans.t_y);
	pt->y1 += (150 + fdf->trans.t_y);
}

void	init_y(int i, int j, t_point *pt, t_fdf *fdf)
{
	pt->x0 = j * (ZOOM + fdf->trans.zoom);
	pt->x1 = j * (ZOOM + fdf->trans.zoom);
	pt->y0 = i * (ZOOM + fdf->trans.zoom);
	pt->y1 = (i + 1) * (ZOOM + fdf->trans.zoom);
	pt->z0 = fdf->map.matrice[i][j];
	pt->z1 = fdf->map.matrice[i + 1][j];
	if (pt->z0 || pt->z1)
		pt->color = 0xFF0000;
	else
		pt->color = 0xFFFFFF;
	isometric(pt, fdf);
	pt->x0 += (250 + fdf->trans.t_x);
	pt->x1 += (250 + fdf->trans.t_x);
	pt->y0 += (150 + fdf->trans.t_y);
	pt->y1 += (150 + fdf->trans.t_y);
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
