/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhernand <rhernand@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:51:28 by rhernand          #+#    #+#             */
/*   Updated: 2024/10/28 18:46:51 by rhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
# define FDF
# include "minilibx-linux/mlx.h"
# include <unistd.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	x3;
	int	y3;
	int	z3;
}
    t_point;


#endif