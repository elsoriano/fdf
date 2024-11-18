/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:51:28 by rhernand          #+#    #+#             */
/*   Updated: 2024/11/18 21:07:53 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_data
{
	int		cols;
	int		rows;
	int		**pts;

	void	*mlx_ses;
	void	*mlx_win;
}		t_data;

typedef struct s_iso
{
	float	x;
	float	y;
}		t_iso;

void	ft_put_nb(char *line, int row, t_data *data);
void	ft_alloc_pts(t_data *data);
void	ft_set_matrix(char *map, t_data *data);
void	ft_count_cols(char *buff, t_data *data);
void	ft_map_size(char *map, t_data *data);
void	ft_draw_line(t_iso x, t_iso y, t_data *data);
void	ft_draw_map(t_data *data);
void	ft_clean_exit(t_data *data, char *msg);

#endif