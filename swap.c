#include "utils.h"

void	swap_a(t_list **stack_a)
{
	t_list	*temp;
	t_list	*begin;

	if (*stack_a == NULL || ft_lstsize(*stack_a) == 1)
		return ;
	begin = (*stack_a)->next;
	temp = (*stack_a)->next->next;
	(*stack_a)->next->next = (*stack_a);
	(*stack_a)->next = temp;
	(*stack_a) = begin;
}

void	swap_b(t_list **stack_b)
{
	t_list	*temp;
	t_list	*begin;

	if (*stack_b == NULL || ft_lstsize(*stack_b) == 1)
		return ;
	begin = (*stack_b)->next;
	temp = (*stack_b)->next->next;
	(*stack_b)->next->next = (*stack_b);
	(*stack_b)->next = temp;
	(*stack_b) = begin;
}

void	swap_both(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}
