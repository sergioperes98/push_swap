/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilaca- <svilaca-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:01:13 by svilaca-          #+#    #+#             */
/*   Updated: 2023/05/10 14:30:28 by svilaca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    stack_a_rotate(t_list *stack_a)
{
    t_element	*min;

	min = min_value(stack_a);
	if (min_side(stack_a, min))
	{
		while (min->previous)
			ra(stack_a);
	}
	else
		while (min->previous)
			rra(stack_a);
}

void    double_rotate(t_list *stack_a, t_element *best, t_list *stack_b, t_element *value)
{
    if (min_side(stack_a, best) && min_side(stack_b, value))
        while (best->previous && value->previous)
            rr(stack_a, stack_b);
    else if (!(min_side(stack_a, best)) && !(min_side(stack_b, value)))
        while (best->previous && value->previous)
            rrr(stack_a, stack_b);
}
