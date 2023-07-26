/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:53:58 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/07/26 04:11:01 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_strjoin_line(char *stash, char *buff)
{
	int		i;
	int		j;
	char	*temp;

	if (!stash && !buff)
		return (NULL);
	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	temp = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buff) + 1));
	if (!temp)
		return (NULL);
	i = -1;
	while (stash[++i])
		temp[i] = stash[i];
	j = -1;
	while (buff[++j])
		temp[i++] = buff[j];
	temp[i] = '\0';
	return (free(stash), free(buff), temp);
}
