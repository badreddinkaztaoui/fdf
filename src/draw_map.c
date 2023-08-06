/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 04:21:15 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/08/06 04:24:09 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_map(t_fdf *fdf)
{
	int	i;
	int	j;

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
}
