/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilaca- <svilaca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:26:11 by svilaca-          #+#    #+#             */
/*   Updated: 2023/04/03 17:04:01 by svilaca-         ###   ########.fr       */
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
		stack_a->first = temp->next;
		free(temp);
		temp = stack_a->first;
	}
	write(2, "error\n", 6);
	exit(1);
}

int	is_number(const char *str)
{
	int	i;

	i = -1;
	while (str[++i] && !((str[i] >= 9 && str[i] <= 13) || (str[i] == 32)))
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}

void	ft_atoi2(t_list *stack_a, const char *str)
{
	int	j;
	int	res;

	res = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	j = (*str != '-') - (*str == '-');
	if (*str == '-' || *str == '+')
		str++;
	if (is_number(str) && *str)
	{
		while (*str && (*str >= '0' && *str <= '9'))
			res = (res * 10) + *str++ - '0';
		new_element(stack_a, res * j);
	}
	else if (*str)
		list_free(stack_a);
	if (((*str >= 9 && *str <= 13) || (*str == 32)) && *str)
		ft_atoi2(stack_a, str);
}

int	main(void)
{
	static t_list	stack_a;
	char	*str = " -545 94f4 001\t  k";

	ft_atoi2(&stack_a, str);
	view_list(&stack_a);
	return (0);
}
