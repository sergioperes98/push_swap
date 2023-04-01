/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilaca- <svilaca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:55:14 by svilaca-          #+#    #+#             */
/*   Updated: 2023/04/01 19:01:40 by svilaca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_list *stack)
{
	t_element	*temp;

	if (stack && stack->size > 1)
	{
		temp = stack->first;
		stack->first = stack->first->next;
		stack->first->previous = NULL;
		stack->last->next = temp;
		temp->next = NULL;
		temp->previous = stack->last;
		stack->last = stack->last->next;
	}
}

void	ra(t_list *stack_a)
{
	rotate(stack_a);
	printf("ra\n");
}

void	rb(t_list *stack_b)
{
	rotate(stack_b);
	printf("rb\n");
}

void	rr(t_list *stack_a, t_list *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	printf("rr\n");
}
