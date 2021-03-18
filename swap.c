#include "utils.h"

void	swap_a(t_list **stack_a)
{
	t_list	*top;
	t_list	*next;
	t_list	*temp;

	if (*stack_a == NULL || ft_lstsize(*stack_a) == 1)
		return ;
	temp = (*stack_a)->next->next;
	top = (*stack_a)->next;
	next = (*stack_a);
	top->next = next;
	top->prev = NULL;
	next->next = temp;
	next->prev = top;
	if (temp != NULL)
		temp->prev = next;
	*stack_a = top;
}

void	swap_b(t_list **stack_b)
{
	t_list	*top;
	t_list	*next;
	t_list	*temp;

	if (*stack_b == NULL || ft_lstsize(*stack_b) == 1)
		return ;
	temp = (*stack_b)->next->next;
	top = (*stack_b)->next;
	next = (*stack_b);
	top->next = next;
	top->prev = NULL;
	next->next = temp;
	next->prev = top;
	if (temp != NULL)
		temp->prev = next;
	*stack_b = top;
}

void	swap_both(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}
