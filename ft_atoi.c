/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilaca- <svilaca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:26:11 by svilaca-          #+#    #+#             */
/*   Updated: 2023/04/03 17:56:48 by svilaca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_atoi2(t_list *stack_a, const char *str)
{
	long long	j;
	long long	res;

	res = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	j = (*str != '-') - (*str == '-');
	if ((*str == '-' || *str == '+') && (*(str + 1) >= '0' && *(str + 1) <= '9'))
		str++;
	if (!(*str))
		return ;
	while (*str && (*str >= '0' && *str <= '9'))
		res = (res * 10) + *str++ - '0';
	res *= j;
	new_element(stack_a, res);
	if (((*str >= 9 && *str <= 13) || (*str == 32)))
		ft_atoi2(stack_a, str);
	else if (*str || (res < INT_MIN || res > INT_MAX))
		list_free(stack_a, 1);
}

int	main(int argc, char **argv)
{
	static t_list	stack_a;
	int				i;

	i = 0;
	while (++i < argc)
		ft_atoi2(&stack_a, argv[i]);
	view_list(&stack_a);
	list_free(&stack_a, 0);
	return (0);
}
