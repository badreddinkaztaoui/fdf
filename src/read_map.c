/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:56:19 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/07/31 22:50:41 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	initialize_pt(int x, int y)
{
	t_point	pt;

	pt.x0 = x;
	pt.x1 = x + 1;
	pt.y0 = y;
	pt.y1 = y + 1;
	pt.xinc = 0;
	pt.yinc = 0;
	return (pt);
}

void	read_map(int fd, t_image *img, t_map *map)
{
	char	*stash;
	int		i;
	int		j;

	stash = ft_flatmap(fd, map);
	ft_fillmatrice(stash, map);
	i = -1;
	while (++i < map->y)
	{
		j = -1;
		while (++j < map->x)
			bresenhams(img, initialize_pt(j, i));
	}
}
