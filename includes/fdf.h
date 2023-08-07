/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:19:59 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/08/07 05:00:33 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <math.h>

# define BUFFER_SIZE 10
# define WINDOW_NAME "fdf"
# define WINDOW_WIDTH 1900
# define WINDOW_HEIGHT 900
# define ZOOM 40

typedef struct s_window
{
	int		win_w;
	int		win_h;
	void	*mlx_win;
	void	*mlx;
}	t_window;

typedef struct s_map
{
	int	x;
	int	y;
	int	**matrice;
	int	row_len;
}	t_map;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_transform {
	int	t_x;
	int	t_y;
	int	scale;
	int	zoom;
}	t_transform;

typedef struct s_fdf
{
	t_window	win;
	t_image		img;
	t_map		map;
	t_transform	trans;
}	t_fdf;

typedef struct s_point
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	z0;
	int	z1;
	int	xinc;
	int	yinc;
	int	color;
}	t_point;

void	read_map(int fd, t_fdf *fdf);
void	ft_error(char *err);
char	*ft_newline(char *str);
char	*get_next_line(int fd);
void	ft_freematrice(char **matrice);
int		ft_matricelen(char **matrice);
char	*ft_flatmap(int fd, t_map *map);
void	ft_fillmatrice(char *stash, t_map *map);
void	ft_printmatrice(t_map *map);
void	bresenhams(t_fdf *fdf, t_point pt);
void	ft_putpixel(t_fdf *fdf, int x, int y, int color);
t_point	ft_init_pt(int i, int j, t_fdf *fdf, char dir);
void	draw_map(t_fdf *fdf);
int		onkeypress(int key, t_fdf *fdf);
int		onmousemove(int key, int x, int y, t_fdf *fdf);
int		onclose(t_fdf *fdf);

#endif
