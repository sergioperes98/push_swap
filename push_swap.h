/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilaca- <svilaca-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:00:53 by svilaca-          #+#    #+#             */
/*   Updated: 2023/05/03 19:10:41 by svilaca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct t_element
{
	int					data;
	struct t_element	*next;
	struct t_element	*previous;
}						t_element;

typedef struct t_list
{
	t_element	*first;
	t_element	*last;
	int			size;
}				t_list;

// #### list_utils ####
t_list	*new_element(t_list *list, int data);
void	view_list(t_list *list);
void	list_free(t_list *stack_a, int error);

// #### operations ####
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *stack_b);
void	pa(t_list *stack_a, t_list *stack_b);
void	pb(t_list *stack_a, t_list *stack_b);
void	ra(t_list *stack_a);
void	rb(t_list *stack_b);
void	rr(t_list *stack_a, t_list *stack_b);
void	rra(t_list *stack_a);
void	rrb(t_list *stack_b);
void	rrr(t_list *stack_a, t_list *stack_b);

// #### initializer ####
void	ft_atoi(t_list *stack_a, const char *str);
void	check_double(t_list *stack_a);
int		sorted_list(t_list *stack_a);

// #### little_sort ####
void		sort_three(t_list *stack_a);
t_element	*min_value(t_list *stack_a);
int			min_side(t_list *stack_a, t_element	*min);
void		push_min(t_list *stack_a, t_list *stack_b);
void		sort_five(t_list *stack_a, t_list *stack_b);

// #### mean ####
long long	mean(t_list *stack_a);
void    	push_mean(t_list *stack_a, t_list *stack_b);

#endif