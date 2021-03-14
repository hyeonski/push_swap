#include "utils.h"

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*begin_a;
	t_list	*begin_b;

	if (*stack_b == NULL)
		return ;
	begin_b = (*stack_b)->next;
	begin_a = (*stack_b);
	(*stack_b)->next = (*stack_a);
	(*stack_a) = begin_a;
	(*stack_b) = begin_b;
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*begin_a;
	t_list	*begin_b;

	if (*stack_a == NULL)
		return ;
	begin_a = (*stack_a)->next;
	begin_b = (*stack_a);
	(*stack_a)->next = (*stack_b);
	(*stack_b) = begin_b;
	(*stack_a) = begin_a;
}
