/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:23:35 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/08/06 02:54:21 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	set_incs(int p0, int p1)
{
	if (p0 < p1)
		return (1);
	return (-1);
}

static int	set_err(int dx, int dy)
{
	if (dx > dy)
		return (dx / 2);
	return (-dy / 2);
}

void	bresenhams(t_fdf *fdf, t_point pt)
{
	int	dx;
	int	dy;
	int	err;
	int	e2;

	dx = abs(pt.x1 - pt.x0);
	dy = abs(pt.y1 - pt.y0);
	pt.xinc = set_incs(pt.x0, pt.x1);
	pt.yinc = set_incs(pt.y0, pt.y1);
	err = set_err(dx, dy);
	while ((pt.x0 - pt.x1) || (pt.y0 - pt.y1))
	{
		ft_putpixel(fdf, pt.x0, pt.y0, pt.color);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			pt.x0 += pt.xinc;
		}
		if (e2 < dy)
		{
			err += dx;
			pt.y0 += pt.yinc;
		}
	}
}
