/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilaca- <svilaca-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:20:21 by svilaca-          #+#    #+#             */
/*   Updated: 2023/06/02 19:10:22 by svilaca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element   *best_friend(t_list *stack_a, t_element *stack_b)
{
    t_element   *temp;
    t_element   *friend;
    long long   diff;

    temp = stack_a->first;
    diff = INT_MAX;
    while (temp)
    {
        if (temp->data > stack_b->data && diff > (temp->data - stack_b->data))
        {
            diff = temp->data - stack_b->data;
            friend = temp;
        }
        temp = temp->next;
    }
    return (friend);
}

int cost(t_list *stack, t_element *value)
{
    int i;

    i = 0;
    if (min_side(stack, value))
    {
        while (value->previous)
        {
            value = value->previous;
            i++;
        }
    }
    else
    {
        while (value->next)
        {
            value = value->next;
            i++;
        }
        i++;
    }
    return (i);
}

t_element   **min_cost(t_list *stack_a, t_list *stack_b)
{
    t_element   *temp;
    t_element   **array;
    int         total_cost;
    int         min_cost;

    temp = stack_b->first;
    array = (t_element **)malloc(2 * sizeof(t_element *));
    min_cost = INT_MAX;
    while (temp)
    {
        total_cost = cost(stack_a, best_friend(stack_a, temp)) + cost(stack_b, temp);
        if (total_cost < min_cost)
        {
            min_cost = total_cost;
            array[0] = best_friend(stack_a, temp);
            array[1] = temp;
        }
        temp = temp->next;
    }
    return (array);
}

void    top_value(t_list *stack, t_element *value, int i)
{
	if (min_side(stack, value))
	{
		while (value->previous)
        {
			if (i == 0)
                ra(stack);
            else
                rb(stack);
        }
	}
	else
    {
		while (value->previous)
        {
			if (i == 0)
                rra(stack);
            else
                rrb(stack);
        }
	}
}

void    algo(t_list *stack_a, t_list *stack_b)
{
    t_element   **array;
    t_element   *temp;

    temp = stack_b->first;
    while (temp)
    {
        array = min_cost(stack_a, stack_b);
        double_rotate(stack_a, array[0], stack_b, array[1]);
        top_value(stack_a, array[0], 0);
        top_value(stack_b, array[1], 1);
        pa(stack_a, stack_b);
        temp = stack_b->first;
    }
    free(array);
    stack_a_rotate(stack_a);
}
