/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilaca- <svilaca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 04:36:59 by svilaca-          #+#    #+#             */
/*   Updated: 2023/03/30 06:01:05 by svilaca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list *stack)
{
	t_element	*temp;

	if (stack && stack->size > 1)
	{
		temp = stack->first;
		stack->first = stack->last;
		stack->first->next = temp;
		stack->last = stack->last->previous;
		stack->last->next = NULL;
		temp->previous = stack->first;
		stack->first->previous = NULL;
	}
}

void	rra(t_list *stack_a)
{
	reverse_rotate(stack_a);
	printf("rra\n");
}

void	rrb(t_list *stack_b)
{
	reverse_rotate(stack_b);
	printf("rrb\n");
}

void	rrr(t_list *stack_a, t_list *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	printf("rrr\n");
}
