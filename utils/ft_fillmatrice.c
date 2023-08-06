/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillmatrice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 03:20:51 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/08/06 01:35:21 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static char	**get_col(char *str)
{
	char	*trim;
	char	**split;

	trim = ft_strtrim(str, "\n");
	split = ft_split(trim, ' ');
	free(trim);
	return (split);
}

void	ft_fillmatrice(char *stash, t_map *map)
{
	int		i;
	int		j;
	char	**rows;
	char	**column;

	map->matrice = malloc(sizeof(int *) * (map->y));
	i = -1;
	while (++i < map->y)
		map->matrice[i] = malloc(sizeof(int) * (map->x));
	rows = ft_split(stash, '\n');
	i = -1;
	while (++i < map->y)
	{
		column = get_col(rows[i]);
		j = -1;
		while (++j < map->x)
			map->matrice[i][j] = ft_atoi(column[j]);
		ft_freematrice(column);
	}
	ft_freematrice(rows);
}
