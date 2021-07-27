#include "../../include/push_swap.h"

int 	is_duplicate_in_stack(t_node *stack)
{

	t_node *i = stack;
	t_node *j = stack->next;


	while(i != NULL)
	{
		j = i->next;
		while(j != NULL)
		{
			if (i->data == j->data)
			{
				// printf("i->data %d\n", i->data);
				// printf("j->data %d\n", j->data);
				return(1);
			}
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}


// int 	is_max_int(long long nb)
// {
//             // printf("%lu \n", nb);

// 	if (nb >= 2147483647 )
// 		return(1);
// 	else if (nb <= -2147483648)
// 		return(1);
// 	return (0);
// }

// int 	is_max_int_in_stack(t_node *stack)
// {
// 	int * size = 0;
// 	// stack = build_stack("1 2147483647 0", &size);
// 	t_node *tmp = stack;
// 	long long int integer_min = -2147483648;
// 	while(tmp != NULL)
// 	{
// 		pint(tmp->data);
// 		if (tmp->data >= 2147483647 || tmp->data <= integer_min)
// 			return(1);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }

int	is_empty(char *str)
{
	if (str == NULL || !ft_strncmp("",str, 1))
	{
		return(1);
	}
	return(0);

}


/**
 * DRAFT
*/

// // doit changer d'algo car prendre en compte des int entier !!!!
// int		is_duplicate(char *str)
// {
// 	int i;
// 	int j;
// 	i = 0;
// 	j = 0;
// 	// while (str[i] + 1 != '\0')
// 	// {
// 	// 	pchar(str[i] + 1);
// 	// 	while (str[j] != '\0')
// 	// 	{
// 	// 		if (str[i] == str[j])
// 	// 			return(1);
// 	// 		j++;
// 	// 	}
// 	// 	i++;
// 	// }

// 	while (str[i] != '\0')
// 	{
// 		j = i + 1;
// 		while (str[j] != '\0')
// 		{
// 			// pint(i);
// 			// pchar(str[i]);
// 			// pchar(str[j]);

// 			if (str[i] == str[j])
// 			{
// 				// pchar(str[i]);
// 				// pchar(str[j]);
// 				return(1);
// 			}

// 			j++;
// 		}
// 		i++;
// 		// printf("i %d\n", i);
// 		// printf("j %d\n", j);

// 	}
// 	return(0);
// }
