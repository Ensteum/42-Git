/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <ppezzull@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:10:11 by ppezzull          #+#    #+#             */
/*   Updated: 2023/09/26 15:10:14 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void error(char *message)
{
    ft_printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void free_matrix(t_point **matrix)
{
    int y;

    y = 0;
    while (matrix[y])
	{
        free(matrix[y]);
		y++;
	}
    free(matrix);
}

float	fmodule(float i)
{
	return (i < 0) ? -i : i;
}

void	zoom(t_point *a, t_point *b, t_point *param)
{
	a->x *= param->scale;
	a->y *= param->scale;
	b->x *= param->scale;
	b->y *= param->scale;
	a->z *= param->z_scale;
	b->z *= param->z_scale;
}

void	isometric(t_point *point, double angle)
{
	point->x = (point->x - point->y) * cos(angle);
	point->y = (point->x + point->y) * sin(angle) - point->z;
}