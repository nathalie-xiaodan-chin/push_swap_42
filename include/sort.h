#ifndef SORT_H
# define SORT_H
# include "struct.h"

void	three_nb_sort(t_node **stack_a, int count);
void	radix_sort(t_node **stack_a, int count);
void	test_radix_sort(char *list_nb);
int		find_pos(t_node * list, int value);
void	find_smallest_nb(t_node *list, int *s_value, int *s_pos, int biggest_nb);
void	find_biggest_nb(t_node *list, int *b_value, int *b_pos);
void	four_nb_sort(t_node **stack_a, t_node**stack_b, int i);
void	five_nb_sort(t_node **stack_a, t_node**stack_b, int i);
void	five_or_four_nb(t_node **stack_a, int count);

#endif
