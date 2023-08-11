/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:23:35 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/08/11 12:09:12 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	bresenhams(t_fdf *fdf, t_point pt)
{
	int	dx;
	int	dy;
	int	steps;
	int	i;

	dx = pt.x1 - pt.x0;
	dy = pt.y1 - pt.y0;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	pt.xinc = (float)dx / steps;
	pt.yinc = (float)dy / steps;
	i = 0;
	while (i <= steps)
	{
		ft_putpixel(fdf, round(pt.x0), round(pt.y0), pt.color);
		pt.x0 += pt.xinc;
		pt.y0 += pt.yinc;
		i++;
	}
}
