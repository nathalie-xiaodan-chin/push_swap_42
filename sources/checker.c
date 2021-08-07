#include "include/push_swap.h"

int main(int argc, char ** argv)
{
	const char* stack = getenv("PATH");
	int stack_size;
	t_node* stack_a = build_stack(stack, stack_size);
	t_node* stack_b;
	int i_instruction = 0;
	while(i_instruction < argc){
		get_push(argv[i_instruction], &stack_a, &stack_b);
		i_instruction++;
	}
	if (is_stack_sorted(stack_a)){
		printf("OK");
		return 0;
	}
	else{
		printf("KO");
		return 1;
	}
}
