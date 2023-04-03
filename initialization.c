/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilaca- <svilaca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 07:45:18 by svilaca-          #+#    #+#             */
/*   Updated: 2023/04/03 17:39:06 by svilaca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_atoi(const char *nptr)
// {
// 	int	i;
// 	int	j;
// 	int	res;

// 	i = 0;
// 	j = 1;
// 	res = 0;
// 	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
// 		i++;
	// if (nptr[i] == '-' || nptr[i] == '+')
	// {
	// 	if (nptr[i] == '-')
	// 		j = j * (-1);
	// 	i++;
	// }
	// while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	// {
	// 	res = (res * 10) + nptr[i] - '0';
	// 	i++;
	// }
// 	return (res * j);
// }

void	ft_atoi2(t_list stack_a, const char *str)
{
	int	j;

	j = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			j = j * (-1);
		str++;
	}

}

t_list	initializer(int argc, char **argv)
{
	static t_list	stack_a;
	long int		nb;
	int				i;

	nb = 0;
	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		new_element(&stack_a, nb);
		i++;
	}
	return (stack_a);
}
