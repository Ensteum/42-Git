/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pietro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:48:42 by pietro            #+#    #+#             */
/*   Updated: 2023/03/07 15:48:43 by pietro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_numbers_sort(t_program **program)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = ft_stack_index((*program)->a, 0)->num;
	n2 = ft_stack_index((*program)->a, 1)->num;
	n3 = ft_stack_index((*program)->a, 2)->num;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		sa(*program);
	else if (n1 < n2 && n2 > n3 && n3 < n1)
		rra(*program);
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ra(*program);
	else if (n1 < n2 && n2 > n3 && n3 > n1)
	{
		sa(*program);
		ra(*program);
	}
	else if (n1 > n2 && n1 > n2 && n1 > n3)
	{
		sa(*program);
		rra(*program);
	}
}

void	ten_numbers_sort(t_program **program)
{
	int		i;
	int		b_len;

	while (stack_size((*program)->a) > 3)
	{
		put_stack_on_top_of_a(*program, get_min_idx((*program)->a));
		pb(*program);
	}
	three_numbers_sort(program);
	b_len = stack_size((*program)->b);
	i = -1;
	while (i++ < b_len)
		pa(*program);
}

void	push_swap(t_program *program)
{
	if (stack_size(program->a) == 2)
	{
		if (program->a->num > program->a->next->num)
			sa(program);
	}
	else if (stack_size(program->a) == 3)
		three_numbers_sort(&program);
	else if (stack_size(program->a) <= 10)
		ten_numbers_sort(&program);
	else if (stack_size(program->a) <= 100)
		hundred_numbers_sort(&program);
	else
		over_hundred_numbers_sort(&program);
}
