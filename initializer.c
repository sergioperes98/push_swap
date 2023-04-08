/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilaca- <svilaca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:26:11 by svilaca-          #+#    #+#             */
/*   Updated: 2023/04/04 21:44:02 by svilaca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_list(t_list *stack_a)
{
	t_element	*temp;
	t_element	*temp2;

	if (!(stack_a->first))
		return (0);
	temp = stack_a->first;
	temp2 = temp->next;
	while (temp2)
	{
		if (temp->data > temp2->data)
			return (0);
		temp = temp->next;
		temp2 = temp2->next;
	}
	return (1);
}

void	check_double(t_list *stack_a)
{
	t_element	*temp;
	t_element	*temp2;

	if (!(stack_a->first))
		return ;
	temp = stack_a->first;
	temp2 = temp->next;
	while (temp->next)
	{
		while (temp2)
		{
			if (temp->data == temp2->data)
				list_free(stack_a, 1);
			temp2 = temp2->next;
		}
		temp = temp->next;
		temp2 = temp->next;
	}
}

void	ft_atoi(t_list *stack_a, const char *str)
{
	long long	j;
	long long	res;

	res = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	j = (*str != '-') - (*str == '-');
	if ((*str == '-' || *str == '+') \
	&& (*(str + 1) >= '0' && *(str + 1) <= '9'))
		str++;
	if (!(*str))
		return ;
	while (*str && (*str >= '0' && *str <= '9'))
		res = (res * 10) + *str++ - '0';
	res *= j;
	new_element(stack_a, res);
	if (((*str >= 9 && *str <= 13) || (*str == 32)))
		ft_atoi(stack_a, str);
	else if (*str || (res < INT_MIN || res > INT_MAX))
		list_free(stack_a, 1);
}

int	main(int argc, char **argv)
{
	static t_list	stack_a;
	static t_list	stack_b;
	int				i;

	i = 0;
	while (++i < argc)
		ft_atoi(&stack_a, argv[i]);
	check_double(&stack_a);
	if (sorted_list(&stack_a))
		return (0);
	if (stack_a.size == 3)
		sort_three(&stack_a);
	if (stack_a.size == 4 || stack_a.size == 5)
		sort_five(&stack_a, &stack_b);
	printf("STACK A\n");
	printf("size: %d\n", stack_a.size);
	view_list(&stack_a);
	printf(" \n");
	printf("STACK B\n");
	printf("size: %d\n", stack_b.size);
	view_list(&stack_b);
	list_free(&stack_a, 0);
	list_free(&stack_b, 0);
	return (0);
}
