/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:55:33 by rhernand          #+#    #+#             */
/*   Updated: 2024/11/02 20:03:48 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/minilibx-linux/mlx.h"
#include "../inc/libft/inc/libft.h"
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void	ft_draw_line(float x, float y, float x1, float y1, t_data *data)
{
	float	x_step;
	float	y_step;
	float	temp;
	float	zoom;

	zoom = 20;
	x *= zoom;
	x1 *= zoom;
	y *= zoom;
	y1 *= zoom;
	x_step = x1 - x;
	y_step = y1 - y;
	temp = MAX(x_step, y_step);
	x_step /= temp;
	y_step /= temp;
	while (x != x1 || y != y1)
	{
		if (mlx_pixel_put(data->mlx_ses, data->mlx_win, (int)x, (int)y, 0xfffafa) == -1)
			ft_clean_exit(data, "Error putting pixel");
		x += x_step;
		y += y_step;
	}
}

void	ft_draw_map(t_data *data)
{
	int		x;
	int		y;
	
	x = 0;
	y = 0;
	data->mlx_ses = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ses, 1000, 1000, "FDF");
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			ft_draw_line((float)x, (float)y, (float)x, (float)(y + 1), data);
			ft_draw_line((float)x, (float)y, (float)(x + 1), (float) y, data);
			x++;
		}
		y++;
	}
}
