/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 01:39:45 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/07/30 01:46:25 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_flatmap(int fd, t_map *map)
{
	char	*line;
	char	*stash;
	char	**rows;
	int		length;

	stash = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		stash = ft_strjoin(stash, line);
		rows = ft_split(line, ' ');
		if (map->y == 0)
			length = ft_matricelen(rows);
		if (length != ft_matricelen(rows))
			ft_error("Error while reading the map.");
		map->x = length;
		ft_freematrice(rows);
		map->y++;
	}
	return (stash);
}
