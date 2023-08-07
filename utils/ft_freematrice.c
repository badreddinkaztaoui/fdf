/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freematrice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 01:46:38 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/08/06 11:13:41 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_freematrice(char **matrice)
{
	int	i;

	i = -1;
	while (matrice && matrice[++i])
		free(matrice[i]);
	free(matrice);
}
