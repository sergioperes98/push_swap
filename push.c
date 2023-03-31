/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilaca- <svilaca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:54:58 by svilaca-          #+#    #+#             */
/*   Updated: 2023/03/30 06:17:17 by svilaca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list *src, t_list *dst)
{
	t_element	*temp;

	if (src->first)
	{
		temp = src->first;
		if (src->size > 1)
		{
			src->first = src->first->next;
			src->first->previous = NULL;
		}
		else
		{
			src->first = NULL;
			src->last = NULL;
		}
		temp->next = dst->first;
		temp->previous = NULL;
		dst->first->previous = temp;
		dst->first = temp;
	}
}

void	pa(t_list *stack_a, t_list *stack_b)
{
	push(stack_b, stack_a);
	printf("pa\n");
}

void	pb(t_list *stack_a, t_list *stack_b)
{
	push(stack_a, stack_b);
	printf("pb\n");
}
