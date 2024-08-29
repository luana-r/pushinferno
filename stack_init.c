/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:04:07 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/08/28 21:04:48 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		n = ft_atol(argv[i], *a);
		if (n > INT_MAX || n < INT_MIN)
			ft_error(*a);
		if (check_double(n, argv, i, *a) == 1)
			ft_error(*a);
		append_node(a, (int)n);
		i++;
	}
}

long	ft_atol(const char *str, t_stack_node *a)
{
	int		i;
	int		is_neg;
	long	num_int;

	i = 0;
	num_int = 0;
	is_neg = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			is_neg = 1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9' || str[i] == '\0')
		ft_error(a);
	while (str[i] > 47 && str[i] < 58 && str[i] != '\0')
	{
		num_int = (10 * num_int) + ((unsigned char)(str[i]) - '0');
		i++;
	}
	if (is_neg)
		num_int = -num_int;
	return (num_int);
}

int	check_double(long n, char **str, int i, t_stack_node *a)
{
	int	is_double;

	is_double = 0;
	i++;
	while (str[i])
	{
		if (n == ft_atol(str[i], a))
			is_double = 1;
		i++;
	}
	return (is_double);
}

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
