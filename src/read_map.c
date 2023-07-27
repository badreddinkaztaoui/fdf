/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:56:19 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/07/27 18:22:36 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_matrice(char **matrice)
{
	int	i;

	i = -1;
	while (matrice[++i])
		free(matrice[i]);
	free(matrice);
}

int	ft_dstrlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	get_map_data(int fd, t_map *map)
{
	char	*line;
	char	**numbers;
	char	*stash;

	stash = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		stash = ft_strjoin(stash, line);
		numbers = ft_split(line, ' ');
		map->x = ft_dstrlen(numbers);
		free_matrice(numbers);
		map->y++;
	}
	puts(stash);
}

void	read_map(int fd, t_map *map)
{
	get_map_data(fd, map);
}
