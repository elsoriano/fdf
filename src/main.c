/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:50:27 by rhernand          #+#    #+#             */
/*   Updated: 2024/11/01 11:46:00 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/libft/inc/libft.h"

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
	exit(EXIT_SUCCESS);
}

void	ft_count_cols(char *buff, t_data *data)
{
	char		**split;
	static int	cols = -1;
	int			i;

	i = 0;
	split = ft_split(buff, ' ');
	if (!split)
	{
		free(buff);
		ft_clean_exit(data, "Error reading rows");
	}
	while (split[i])
		i++;
	if (cols != i && cols != -1)
	{
		while (split[i])
			free(split[i++]);
		free(split);
		ft_clean_exit(data, "Lines have different sizes");
	}
	data->cols = i;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	ft_map_size(char *map, t_data *data)
{
	int		fd;
	char	*buff;

	data->rows = 0;
	fd = open(map, O_RDONLY, 0);
	if (fd == -1)
		exit(EXIT_FAILURE);
	while (1 == 1)
	{
		buff = ft_get_next_line(fd);
		if(!buff)
			break;
		ft_count_cols(buff, data);
		free(buff);
		data->rows++;
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	t_data		*data;

	data = (t_data *)malloc(sizeof(t_data *));
	if (argc != 2)
		return (errno = EINVAL, perror("Invalid Number of Arguments"), 1);
	ft_map_size(argv[1], data);
	ft_clean_exit(data, NULL);
	return (0);
}