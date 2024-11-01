/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:50:27 by rhernand          #+#    #+#             */
/*   Updated: 2024/11/01 19:22:03 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/libft/inc/libft.h"
#include "../inc/minilibx-linux/mlx.h"

void	ft_clean_exit(t_data *data, char *msg)
{
	int	i;
	
	i = 0;
	if (data)
	{
		if (data->pts)
		{
			while (data->pts[i])
				free(data->pts[i++]);
			free(data->pts);
		}
	}
	if (msg)
	{
		perror(msg);
		exit(EXIT_FAILURE);
	}
	return;
}

int	main(int argc, char **argv)
{
	t_data		*data;
	int			i;
	int			j;

	i = 0;
	data = (t_data *)malloc(sizeof(t_data *));
	if (argc != 2)
		return (errno = EINVAL, perror("Invalid Number of Arguments"), 1);
	ft_map_size(argv[1], data);
	ft_set_matrix(argv[1], data);
	while (data->pts[i])
	{
		j = 0;
		while(data->pts[i][j] != -1)
		{
			printf("%d", data->pts[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	ft_draw_map(data);
	ft_clean_exit(data, NULL);
	mlx_loop(data->mlx_ses);
	return (0);
}