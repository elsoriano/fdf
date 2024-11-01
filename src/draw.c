/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:55:33 by rhernand          #+#    #+#             */
/*   Updated: 2024/11/01 19:49:09 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/minilibx-linux/mlx.h"
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void	ft_draw_line(int x, int y, int x1, int y1, t_data *data)
{
	float	delta_x;
	float	delta_y;
	float	slope;

	x = x + data->zoom;
	x1 = x1 + data->zoom;
	
	delta_x = (float)x1 - (float)x;
	delta_y = (float)y1 - (float)y;
	slope = delta_y / delta_x;
	
}

void	ft_draw_map(t_data *data)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	data->mlx_ses = mlx_init();
	data->mlx_win = mlx_window(data->mlx_ses, 1000, 1000, "FDF");
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			ft_draw_line(x, y, x + 1, y + 1, data);
			y++;
		}
		y++;
	}
}
