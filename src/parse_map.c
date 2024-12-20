/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:22:28 by rhernand          #+#    #+#             */
/*   Updated: 2024/11/22 12:56:29 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/libft/inc/libft.h"

void	ft_put_nb(char *line, int row, t_data *data)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(line, ' ');
	if (!split)
		ft_clean_pts(data, "Error spliting line");
	while (split[i] && i < data->cols)
	{
		data->pts[row][i] = ft_atoi(split[i]);
		i++;
	}
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	ft_alloc_pts(t_data *data)
{
	int	i;

	i = 0;
	data->pts = (int **)malloc(((data->rows)) * sizeof(int *));
	if (!data->pts)
	{
		free (data);
		perror("Error allocating space");
		exit(EXIT_FAILURE);
	}
	while (i < data->rows)
	{
		data->pts[i] = malloc((data->cols) * sizeof(int));
		if (!data->pts[i])
			ft_clean_pts(data, "Error allocating space");
		i++;
	}
}

void	ft_set_matrix(char *map, t_data *data)
{
	int		fd;
	char	*line;
	int		row;

	ft_alloc_pts(data);
	fd = open(map, O_RDONLY);
	if (!fd)
		ft_clean_pts(data, "Error opening map");
	row = 0;
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line || line[0] == '\n')
			break ;
		ft_put_nb(line, row, data);
		row++;
		free(line);
	}
}

void	ft_count_cols(char *buff, t_data *data)
{
	char		**split;
	int			i;

	i = 0;
	split = ft_split(buff, ' ');
	if (!split)
	{
		free(buff);
		ft_clean_data(data, "Error splitting rows");
	}
	while (split[i])
		i++;
	if (data->cols != i && data->cols != -1)
	{
		i = 0;
		while (split[i])
			free(split[i++]);
		free(split);
		ft_clean_data(data, "Lines have different size");
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
	data->cols = -1;
	fd = open(map, O_RDONLY, 0);
	if (fd == -1)
	{
		perror("Error Opening Map");
		exit(EXIT_FAILURE);
	}
	while (1 == 1)
	{
		buff = ft_get_next_line(fd);
		if (!buff)
			break ;
		ft_count_cols(buff, data);
		free(buff);
		data->rows++;
	}
	close(fd);
}
