/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:55:33 by rhernand          #+#    #+#             */
/*   Updated: 2024/11/02 21:35:26 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/minilibx-linux/mlx.h"
#include "../inc/libft/inc/libft.h"
#include <math.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MOD(a) (a < 0 ? (-a) : (a))

void	ft_persp(float *x, float *y, int z)
{
	*x = (*x - *y)* cos(0.8);
	*y = (*x + *y)* sin(0.8) - (float)z;
}

int	ft_zoomove(float *x, float *y, t_data *data)
{
	int		z;
	float	move;
	float	zoom;

	z = data->pts[(int)*y][(int)*x];
	zoom = 20;
	*x *= zoom;
	*y *= zoom;
	move = 150;
	*x += move;
	*y += move;
	return (z);
}

void	ft_draw_line(float x, float y, float x1, float y1, t_data *data)
{
	float	x_step;
	float	y_step;
	float	temp;
	int		z;
	int		z1;
	int		color;

	color = 0xcd5c5c;
	if (data->pts[(int)y1][(int)x1])
		color = 0xfffafa;
	z = ft_zoomove(&x, &y, data);
	z1 = ft_zoomove(&x1, &y1, data);
	x_step = x1 - x;
	y_step = y1 - y;
	temp = MAX(MOD(x_step), MOD(y_step));
	x_step /= temp;
	y_step /= temp;
	//ft_persp(&x, &y, z);
	//ft_persp(&x1, &y1, z);
	while (x != x1 || y != y1)
	{
		if (mlx_pixel_put(data->mlx_ses, data->mlx_win, (int)x, (int)y, color) == -1)
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
			if (y < data->rows - 1)
				ft_draw_line((float)x, (float)y, (float)x, (float)(y + 1), data);
			if (x < data->cols - 1)
				ft_draw_line((float)x, (float)y, (float)(x + 1), (float) y, data);
			x++;
		}
		y++;
	}
}
