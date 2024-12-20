/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:50:27 by rhernand          #+#    #+#             */
/*   Updated: 2024/11/25 14:22:38 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/libft/inc/libft.h"
#include "../inc/minilibx-linux/mlx.h"

void	ft_clean_data(t_data *data, char *msg)
{
	free (data);
	perror (msg);
	exit (EXIT_FAILURE);
}

int	ft_close(int event)
{
	event += 1;
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_hook(int key, t_data *data)
{
	if (key == 65307 || key == 64)
		ft_clean_pts(data, NULL);
	return (0);
}

void	ft_clean_pts(t_data *data, char *msg)
{
	int	i;

	i = 0;
	if (data)
	{
		while (i < data->rows)
			free(data->pts[i++]);
		free(data->pts);
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

	if (argc != 2)
		return (errno = EINVAL, perror("Invalid Number of Arguments"), 1);
	data = (t_data *)malloc(sizeof(t_data));
	ft_map_size(argv[1], data);
	ft_set_matrix(argv[1], data);
	data->mlx_ses = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ses, 1000, 900, "FDF");
	ft_draw_map(data);
	mlx_key_hook(data->mlx_win, ft_hook, data);
	mlx_hook(data->mlx_win, 17, 0, ft_close, NULL);
	mlx_loop(data->mlx_ses);
	return (0);
}
