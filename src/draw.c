/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:55:33 by rhernand          #+#    #+#             */
/*   Updated: 2024/11/25 14:16:59 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/minilibx-linux/mlx.h"
#include "../inc/libft/inc/libft.h"
#include <math.h>

t_iso	ft_persp(float x, float y, t_data *data)
{
	int		z;
	t_iso	pt;
	float	move;
	float	zoom;

	z = data->pts[(int)y][(int)x];
	pt.x = (x - y) * cos(0.6);
	pt.y = (x + y) * sin(0.6) - z;
	zoom = 1000 / (1 * (data->cols + data->rows));
	pt.x *= zoom;
	pt.y *= zoom;
	move = 400;
	pt.x += move;
	pt.y += 300;
	return (pt);
}

void	ft_draw_line(t_iso pt1, t_iso pt2, t_data *data)
{
	float	x_step;
	float	y_step;
	float	temp;

	x_step = pt2.x - pt1.x;
	y_step = pt2.y - pt1.y;
	temp = fmaxf(fabsf(x_step), fabsf(y_step));
	x_step /= temp;
	y_step /= temp;
	while ((int)(pt2.x - pt1.x) || (int)(pt2.y - pt1.y))
	{
		if (mlx_pixel_put(data->mlx_ses, data->mlx_win, \
				(int)pt1.x, (int)pt1.y, 0xfffafa) == -1)
			ft_clean_pts(data, "Error putting pixel");
		pt1.x += x_step;
		pt1.y += y_step;
	}
}

void	ft_draw_map(t_data *data)
{
	int		x;
	int		y;
	t_iso	pt1;
	t_iso	pt2;

	x = 0;
	y = 0;
	while (y < data->rows -1)
	{
		x = 0;
		while (x < (data->cols - 1))
		{
			if (y < data->rows - 1)
			{
				pt1 = ft_persp((float)x, (float)y, data);
				pt2 = ft_persp((float)x, (float)(y + 1), data);
				ft_draw_line(pt1, pt2, data);
			}
			pt2 = ft_persp((float)(x + 1), (float)y, data);
			ft_draw_line(pt1, pt2, data);
			x++;
		}
		y++;
	}
}
