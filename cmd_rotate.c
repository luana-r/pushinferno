/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:57:41 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/08/28 20:41:25 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
	{
		write(0, "ra", 2);
		write(0, "\n", 1);
	}
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
	{
		write(0, "rb", 2);
		write(0, "\n", 1);
	}
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{	
	rotate(a);
	rotate(b);
	if (!print)
	{
		write(0, "rr", 2);
		write(0, "\n", 1);
	}
}
