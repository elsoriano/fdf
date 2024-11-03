/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:22:28 by rhernand          #+#    #+#             */
/*   Updated: 2024/11/03 16:15:10 by rhernand         ###   ########.fr       */
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
		ft_clean_exit(data, "Error spliting line");
	while(split[i])
	{
		data->pts[row][i] = ft_atoi(split[i]);
		i++;
	}
	i = 0;
	while(split[i])
		free(split[i++]);
	free(split);
}

void	ft_alloc_pts(t_data *data)
{
	int	i;

	i = 0;
	data->pts = (int **)malloc(((data->rows) + 1) * sizeof(int *));
	if (!data->pts)
		ft_clean_exit(data, "Error allocating space");
	data->pts[data->rows + 1] = NULL;
	while (i < data->rows)
	{
		data->pts[i] = malloc(((data->cols) + 1) * sizeof(int));
		if (!data->pts[i])
			ft_clean_exit(data, "Error allocating space");
		data->pts[i][data->cols + 1] = -1;
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
		ft_clean_exit(data, "Error opening map");
	row = 0;
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		ft_put_nb(line, row, data);
		row++;
		free(line);
	}
	
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