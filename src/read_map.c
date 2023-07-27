/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:56:19 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/07/27 18:05:36 by bkaztaou         ###   ########.fr       */
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

int	dt_strlen(char **s)
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

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		stash = ft_strjoin(stash, line);
		numbers = ft_split(line, ' ');
		map->x = dt_strlen(numbers);
		free_matrice(numbers);
		free(line);
		map->y++;
	}
	puts(stash);
}

void	read_map(int fd, t_map *map)
{
	get_map_data(fd, map);
}
