/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 01:39:45 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/08/06 11:18:17 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_flatmap(int fd, t_map *map)
{
	char	*line;
	char	*stash;
	char	**rows;
	char	*trim;

	stash = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		trim = ft_strtrim(line, "\n");
		rows = ft_split(trim, ' ');
		if (map->y == 0)
			map->row_len = ft_matricelen(rows);
		if (map->row_len != ft_matricelen(rows))
			ft_error("Error while reading the map");
		map->x = map->row_len;
		stash = ft_strjoin(stash, line);
		ft_freematrice(rows);
		free(trim);
		map->y++;
	}
	return (stash);
}
