#include "../../include/push_swap.h"

// #include "../include/push_swap.h"

void	execute_instructions(char *instruction, t_node **stack_a, t_node **stack_b)
{
	if (is_swap(instruction) == 1)
		swap_for_checker(instruction, stack_a, stack_b);
	else if (is_push(instruction) == 1)
		push_for_checker(instruction, stack_a, stack_b);
	else if (is_rotate(instruction) == 1)
		rotate_for_checker(instruction, stack_a, stack_b);
	else if (is_reverse(instruction) == 1)
		reverse_for_checker(instruction, stack_a, stack_b);
}

void	checker(t_node **stack_a, t_node **stack_b)
{
	char *instruction;

	instruction = NULL;
	get_next_line(0, &instruction);

	while (ft_strlen(instruction) > 0)
	{
		// execute instruction ;
		execute_instructions(instruction, stack_a, stack_b);
		get_next_line(0, &instruction);
	}

	// while (get_next_line(0, &instruction) > 0)
	// {
	// 	// execute_instructions(instruction, stack_a, stack_b);
	// 	printf("instruction %s\n", instruction);
	// }


}

int main(int argc, char ** argv)
{
	int			i;
	char		*list_nb;
	int			total_nb;
	t_node		*stack_a;
	t_node		*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	total_nb = 0;
	if (argc == 1)
		error_and_exit();
	else if (argc == 2)
	{
		list_nb = argv[1];
		stack_a = build_stack(list_nb, &total_nb);
		if (stack_a->next == NULL)
			exit(1);
	}
	else if (argc > 2)
	{
		i = 1;
		list_nb = "";
		while (i != argc - 1)
		{
			list_nb = ft_strjoin(list_nb, argv[i]);
			list_nb = ft_strjoin(list_nb, " ");
			i++;
		}
		list_nb = ft_strjoin(list_nb, argv[i]);
		stack_a = build_stack(list_nb, &total_nb);
	}

	// char *str;

	// while (get_next_line(0, &str) > 0)
	// {
	// 	printf("%s\n", str);
	// }

	checker(&stack_a, &stack_b);

	if (is_stack_sorted(stack_a)){
		write(1, "OK\n", 3);
		return 0;
	}
	else{
		write(1, "KO\n", 3);
		return 1;
	}


	// const char* stack = getenv("PATH");
	// int stack_size;
	// t_node* stack_a = build_stack(stack, stack_size);
	// t_node* stack_b;
	// int i_instruction = 0;
	// while(i_instruction < argc){
	// 	get_push(argv[i_instruction], &stack_a, &stack_b);
	// 	i_instruction++;
	// }
	// if (is_stack_sorted(stack_a)){
	// 	printf("OK");
	// 	return 0;
	// }
	// else{
	// 	printf("KO");
	// 	return 1;
	// }
}
