/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilaca- <svilaca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:41:24 by svilaca-          #+#    #+#             */
/*   Updated: 2023/04/01 19:01:45 by svilaca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list *stack)
{
	t_element	*temp;

	if (stack && stack->size > 1)
	{
		temp = stack->first;
		stack->first = stack->first->next;
		stack->first->previous = NULL;
		temp->next = stack->first->next;
		temp->next->previous = temp;
		stack->first->next = temp;
		temp->previous = stack->first;
		if (stack->size == 2)
			stack->last = stack->first->next;
	}
}

void	sa(t_list *stack_a)
{
	swap(stack_a);
	printf("sa\n");
}

void	sb(t_list *stack_b)
{
	swap(stack_b);
	printf("sb\n");
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	printf("ss\n");
}
