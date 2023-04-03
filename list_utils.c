/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilaca- <svilaca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:59:56 by svilaca-          #+#    #+#             */
/*   Updated: 2023/04/03 18:28:13 by svilaca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_element(t_list *list, int data)
{
	t_element			*element;

	element = (t_element *)malloc(sizeof((*element)));
	if (!element)
		return (NULL);
	element->data = data;
	element->next = NULL;
	if (!list->first)
	{
		list->first = element;
		element->previous = NULL;
	}
	else
	{
		list->last->next = element;
		element->previous = list->last;
	}
	list->last = element;
	list->size++;
	return (list);
}

void	view_list(t_list *list)
{
	t_element	*temp;

	temp = list->first;
	printf("NEXT: NULL -> ");
	while (temp)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
	printf("PREV: NULL -> ");
	temp = list->last;
	while (temp)
	{
		printf("%d -> ", temp->data);
		temp = temp->previous;
	}
	printf("NULL\n");
}

void	list_free(t_list *stack_a, int error)
{
	t_element	*temp;

	temp = stack_a->first;
	while (temp)
	{
		stack_a->first = temp->next;
		free(temp);
		temp = stack_a->first;
	}
	if (error)
		write(2, "error\n", 6);
	exit(error);
}
