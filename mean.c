/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mean.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilaca- <svilaca-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:18:58 by svilaca-          #+#    #+#             */
/*   Updated: 2023/05/10 15:03:08 by svilaca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float   mean(t_list *stack_a)
{
    long long   some;
    float       mean;
    t_element   *temp;

    temp = stack_a->first;
    some = 0;
    while (temp)
    {
        some += temp->data;
        temp = temp->next;
    }
    mean = some / stack_a->size;
    return (mean);
}

void    push_mean(t_list *stack_a, t_list *stack_b)
{
    long long   value;
    long long   value2;

    value = stack_a->first->data;
    while (stack_a->size > 5)
    {
        value = stack_a->first->data;
        if (value <= mean(stack_a))
        {
            pb(stack_a, stack_b);
            value2 = stack_b->first->data;
            if (stack_b->size > 1 && value2 <= mean(stack_b))
                rb(stack_b);
        }
        else
            ra(stack_a);
    }
}
