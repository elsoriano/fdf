/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:50:27 by rhernand          #+#    #+#             */
/*   Updated: 2024/11/03 20:27:41 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/libft/inc/libft.h"
#include "../inc/minilibx-linux/mlx.h"

int ft_close(int event)
{
	event += 1;
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_hook(int key, t_data *data)
{
	if (key == 65307 || key == 64)
		ft_clean_exit(data, NULL);
	return (0);
}

void	ft_clean_exit(t_data *data, char *msg)
{
	int	i;
	
	i = 0;
	if (data)
	{
		if (data->pts)
		{
			while (i < data->rows)
				free(data->pts[i++]);
			free(data->pts);
		}
		free(data);
	}
	if (msg)
	{
		perror(msg);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data		*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (argc != 2)
		return (errno = EINVAL, perror("Invalid Number of Arguments"), 1);
	ft_map_size(argv[1], data);
	ft_set_matrix(argv[1], data);
	ft_draw_map(data);
	mlx_key_hook(data->mlx_win, ft_hook, data);
	mlx_hook(data->mlx_win, 17, 0, ft_close, NULL);
	mlx_loop(data->mlx_ses);
	// ft_clean_exit(data, NULL);
	return (0);
}