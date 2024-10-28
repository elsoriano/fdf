/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:50:27 by rhernand          #+#    #+#             */
/*   Updated: 2024/10/29 00:25:29 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_cnvrt_line(int row, char *buff, t_point **pt)
{
	int col;

	col = 1;
	while (buff[col] && buff[col] != '\n')
	{
		pt->x3 = col;
		col++;
	}
}

void	ft_rd_map(int fd, t_point **pt)
{
	int		rd;
	char	*buff;
	int		row;

	row = 1;
	buff = ft_strdup("\0");
	while (*buff)
	{
		buff = ft_get_next_line(fd);
		ft_cnvrt_line(row, buff, pt);
		row++;
	}
}

int	ft_open_map(char *map)
{
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror(strerror(errno));
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	main(int argc, char **argv)
{
	t_point		**pt;
	int			fd;

	pt = NULL;
	if (argc != 2)
		return (errno = EINVAL, perror("Invalid Number of Arguments"), 1);
	fd = ft_open_map(argv[1]);
	ft_rd_map(fd, pt);
	return (0);
}