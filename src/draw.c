/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:55:33 by rhernand          #+#    #+#             */
/*   Updated: 2024/11/18 14:25:08 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/minilibx-linux/mlx.h"
#include "../inc/libft/inc/libft.h"
#include <math.h>

void	ft_persp(float *x, float *y, t_data *data)
{
	int	z;

	z = data->pts[(int)*y][(int)*x] / 2;
	*x = (*x - *y) * cos(0.7);
	*y = (*x + *y) * sin(0.7) - z;
}

void	ft_zoomove(float *x, float *y, t_data *data)
{
	float	move;
	float	zoom_x;

	zoom_x = 1000 / (1 * (data->cols + data->rows));
	*x *= zoom_x;
	*y *= zoom_x;
	move = 400 + data->rows;
	*x += move;
	*y += 400;
}

void	ft_draw_line(float x, float y, float x1, float y1, t_data *data)
{
	float	x_step;
	float	y_step;
	float	temp;
	int		color;

	color = 0xfffafa;
	if (data->pts[(int)y1][(int)x1] \
			|| data->pts[(int)y][(int)x])
		color = 0xfffafa;
	ft_persp(&x, &y, data);
	ft_persp(&x1, &y1, data);
	ft_zoomove(&x, &y, data);
	ft_zoomove(&x1, &y1, data);
	x_step = x1 - x;
	y_step = y1 - y;
	temp = fmaxf(fabsf(x_step), fabsf(y_step));
	x_step /= temp;
	y_step /= temp;
	while ((int)(x1 - x) || (int)(y1 - y))
	{
		if (mlx_pixel_put(data->mlx_ses, data->mlx_win, \
				(int)x, (int)y, color) == -1)
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
	data->mlx_win = mlx_new_window(data->mlx_ses, 1000, 800, "FDF");
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			if (y < data->rows - 1)
				ft_draw_line((float)x, (float)y, \
					(float)x, (float)(y + 1), data);
			if (x < data->cols - 1)
				ft_draw_line((float)x, (float)y, \
					(float)(x + 1), (float) y, data);
			x++;
		}
		y++;
	}
}
