/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 04:11:31 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/07/26 04:13:35 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*ft_realloc(char *buff, size_t o_size, size_t n_size)
{
	void	*n_buff;
	size_t	size;

	if (!buff)
		return (malloc(n_size));
	if (n_size == 0)
		return (free(buff), NULL);
	n_buff = malloc(n_size * sizeof(char));
	if (!n_buff)
		return (NULL);
	if (n_size > o_size)
		size = o_size;
	else
		size = n_size;
	ft_memmove(n_buff, buff, size);
	free(buff);
	return (n_buff);
}
