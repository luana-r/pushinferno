/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:50:49 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/08/28 20:55:02 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			ft_error(t_stack_node *a);
void			free_stack(t_stack_node **stack);
void			sort_three(t_stack_node **a);
t_stack_node	*find_max(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
void			init_stack_a(t_stack_node **a, char **argv);
long			ft_atol(const char *str, t_stack_node *a);
int				check_double(long n, char **str, int i, t_stack_node *a);
t_stack_node	*find_last(t_stack_node *stack);
void			sort_init(t_stack_node **a, t_stack_node **b);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **stack, t_stack_node *top_node, \
								char stack_name);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
t_stack_node	*find_min(t_stack_node *stack);
void			set_target_a(t_stack_node *a, t_stack_node *b);
void			cost_analysis_a(t_stack_node *a, t_stack_node *b);
void			move_a_to_b(t_stack_node **a, t_stack_node **b);
void			rotate_both(t_stack_node **a, t_stack_node **b, \
						t_stack_node *cheapest_node);
void			rev_rotate_both(t_stack_node **a, t_stack_node **b, \
						t_stack_node *cheapest_node);
void			set_target_b(t_stack_node *a, t_stack_node *b);
void			min_on_top(t_stack_node **a);
void			move_b_to_a(t_stack_node **a, t_stack_node **b);
void			append_node(t_stack_node **stack, int n);

#endif