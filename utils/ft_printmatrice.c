/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmatrice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 03:26:21 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/07/30 03:28:13 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_printmatrice(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->y)
	{
		j = -1;
		while (++j < map->x)
			printf("[%d] ", map->matrice[i][j]);
		printf("\n");
	}
}
