/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:23:35 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/07/31 08:32:18 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	dda_algo(t_image *img, t_point pt)
{
	printf("x0: %.1f", pt.x0);
	printf("x1: %.1f", pt.x1);
	printf("y0: %.1f", pt.y0);
	printf("y1: %.1f", pt.y1);
	printf("xinc: %.1f", pt.xinc);
	printf("yinc: %.1f", pt.yinc);
	ft_putpixel(img, pt.x0, pt.y0, 0xFFFFFF);
}
