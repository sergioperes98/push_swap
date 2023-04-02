/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilaca- <svilaca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:26:11 by svilaca-          #+#    #+#             */
/*   Updated: 2023/04/02 20:50:41 by svilaca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	list_free(t_list *stack_a)
{
	t_element	*temp;

	temp = stack_a->first;
	while (temp)
	{
		free(temp);
		temp = temp->next;
	}
	write(2, "error\n", 6);
	exit(1);
}

void	ft_atoi2(t_list *stack_a, const char *str)
{
	int	j;
	int	res;

	j = 1;
	res = 0;
	while (*str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			j *= (-1);
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = (res * 10) + *str - '0';
		str++;
	}
	if (*str != ' ')
		list_free(stack_a);
	new_element(stack_a, res * j);
	if (*str == ' ' && *str != '\0')
		ft_atoi2(stack_a, str);
}

int	main(void)
{
	static t_list	stack_a;
	char	*str = " -545 h 944";

	ft_atoi2(&stack_a, str);
	view_list(&stack_a);
	return (0);
}