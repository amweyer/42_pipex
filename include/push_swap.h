/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:12:05 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/18 18:24:11 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	int				nb;
	int				index;
	int				cost;
	int				size;
	bool			above_median;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				swap(t_stack **head);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);

void				push(t_stack **head_src, t_stack **head_dst);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);

void				rotate(t_stack **head);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);

void				rrotate(t_stack **head);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

/* parsing.c */
void				init_stack(t_stack **a, char **av, int start);
void				add_node(t_stack **a, int n);
void				show_nodes(t_stack *a);
int					is_sorted(t_stack *stack);
void				free_array(char **tab);

/* errors.c */
int					check_error_synthax(char *arg);
int					check_is_int(char *arg);
int					check_error_duplicates(t_stack **a, char *arg);
int					check_errors(t_stack **a, char *arg);
void				free_stack(t_stack **stack);

/* utils.c */
long				ft_atol(char *arg, int *error);
void				free_errors(t_stack **a);
int					ft_max(int a, int b);
int					ft_min(int a, int b);

/* stack_utils.c */
int					get_stack_size(t_stack *stack);
void				update_stack_size(t_stack **stack);
t_stack				*get_max_node(t_stack *stack);
t_stack				*get_min_node(t_stack *stack);

/* sort.c */
void				sort_three(t_stack **stack);
void				sort_turk(t_stack **a, t_stack **b, int stack_size);
void				sort_back(t_stack **a, t_stack **b);
void				sort_min_on_top(t_stack **a);
void				sort(t_stack **a, t_stack **b);

/* sort_utils.c */
void				get_closest(t_stack *node, t_stack **stack);
void				set_target(t_stack **a, t_stack **b);
void				update_index(t_stack **stack);
int					get_median(t_stack *stack);
void				update_median(t_stack **stack);
void				set_cost(t_stack **node);
void				update_cost(t_stack **a, t_stack **b);
t_stack				*get_cheapest(t_stack *stack);

/* move_tuils.c */
void				move(t_stack **a, t_stack **b);
void				rotate_both(t_stack *cheapest, t_stack *target, t_stack **a,
						t_stack **b);
void				rev_rotate_both(t_stack *cheapest, t_stack *target,
						t_stack **a, t_stack **b);
void				move_up(t_stack *node, t_stack **stack, char c);
int					get_index_move(t_stack *node);

/* set_target_back.c */
void				get_closest_bigger(t_stack *node, t_stack **stack);
void				set_target_back(t_stack **a, t_stack **b);
void				move_back(t_stack **a, t_stack **b);

#endif