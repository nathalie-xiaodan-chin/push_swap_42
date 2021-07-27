#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "toolbox.h"
# include "stack.h"
# include "checker.h"
# include "struct.h"
# include "actions.h"
# include "sort.h"
# include "error.h"

# include "../libft/libft.h"

# define RED "\033[1;31m"
# define BLACK "\033[1;30m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define NO_COLOR "\033[0m"

// void	test_radix_sort(char *list_nb);
int 	is_stack_sorted(t_node *stack);
// void	three_nb_sort(t_node **stack_a, int n_elem);
// void	radix_sort(t_node **stack_a, int n_elem);


#endif
