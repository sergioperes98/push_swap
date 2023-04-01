/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilaca- <svilaca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:00:53 by svilaca-          #+#    #+#             */
/*   Updated: 2023/04/01 18:39:29 by svilaca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

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

t_list	*new_element(t_list *list, int data);
void	view_list(t_list *list);
void	sa(t_list *list);
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

t_list	initializer(int argc, char **argv);

#endif