/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilaca- <svilaca-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:58:57 by svilaca-          #+#    #+#             */
/*   Updated: 2023/05/03 20:04:54 by svilaca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list *stack_a)
{
	int	first;
	int	second;
	int	last;

	first = stack_a->first->data;
	second = stack_a->first->next->data;
	last = stack_a->last->data;
	if (sorted_list(stack_a))
		return;
	if (second < last && first > last)
		ra(stack_a);
	else if (last < first && second > first)
		rra(stack_a);
	else if (last < second && first > second)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first < last && second > last)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else
		sa(stack_a);
}

t_element	*min_value(t_list *stack_a)
{
	t_element	*temp;
	t_element	*min;

	temp = stack_a->first->next;
	min = stack_a->first;
	while (temp)
	{
		if (temp->data < min->data)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

int	min_side(t_list *stack_a, t_element	*min)
{
	int	i;

	i = 0;
	while (min)
	{
		min = min->next;
		i++;
	}
	return (i > (stack_a->size / 2));
}

void	push_min(t_list *stack_a, t_list *stack_b)
{
	t_element	*min;

	(void)stack_b;
	min = min_value(stack_a);
	if (min_side(stack_a, min))
	{
		while (min->previous)
			ra(stack_a);
	}
	else
		while (min->previous)
			rra(stack_a);
	pb(stack_a, stack_b);
}

void	sort_five(t_list *stack_a, t_list *stack_b)
{
	while (stack_a->size > 3)
		push_min(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
