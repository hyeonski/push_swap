#include "utils.h"

// void	rotate_a(t_list **stack_a)
// {
// 	t_list	*begin;
// 	t_list	*last;

// 	if (*stack_a == NULL || ft_lstsize(*stack_a) == 1)
// 		return ;
// 	begin = (*stack_a)->next;
// 	last = ft_lstlast(*stack_a);
// 	last->next = *stack_a;
// 	(*stack_a)->next = NULL;
// 	(*stack_a) = begin;
// }

void	rotate_a(t_list **stack_a)
{
	t_list	*temp;

	if (*stack_a == NULL || ft_lstsize(*stack_a) == 1)
		return ;
	temp = *stack_a;
	(*stack_a) = (*stack_a)->next;
	temp->next = NULL;
	ft_lstadd_back(stack_a, temp);
}

// void	rotate_b(t_list **stack_b)
// {
// 	t_list	*begin;
// 	t_list	*last;

// 	if (*stack_b == NULL || ft_lstsize(*stack_b) == 1)
// 		return ;
// 	begin = (*stack_b)->next;
// 	last = ft_lstlast(*stack_b);
// 	last->next = *stack_b;
// 	(*stack_b)->next = NULL;
// 	(*stack_b) = begin;
// }

void	rotate_b(t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b == NULL || ft_lstsize(*stack_b) == 1)
		return ;
	temp = *stack_b;
	(*stack_b) = (*stack_b)->next;
	temp->next = NULL;
	ft_lstadd_back(stack_b, temp);
}

// void	rev_rotate_a(t_list **stack_a)
// {
// 	t_list	*begin;
// 	t_list	*prev_last;

// 	if (*stack_a == NULL || ft_lstsize(*stack_a) == 1)
// 		return ;
// 	begin = ft_lstlast(*stack_a);
// 	prev_last = (*stack_a);
// 	while (prev_last->next && prev_last->next->next)
// 		prev_last = prev_last->next;
// 	prev_last->next = NULL;
// 	begin->next = (*stack_a);
// 	(*stack_a) = begin;
// }

void	rev_rotate_a(t_list **stack_a)
{
	t_list	*begin;
	t_list	*prev_last;

	if (*stack_a == NULL || ft_lstsize(*stack_a) == 1)
		return ;
	begin = ft_lstlast(*stack_a);
	prev_last = (*stack_a);
	while (prev_last->next && prev_last->next->next)
		prev_last = prev_last->next;
	prev_last->next = NULL;
	ft_lstadd_front(stack_a, begin);
}

// void	rev_rotate_b(t_list **stack_b)
// {
// 	t_list	*begin;
// 	t_list	*prev_last;

// 	if (*stack_b == NULL || ft_lstsize(*stack_b) == 1)
// 		return ;
// 	begin = ft_lstlast(*stack_b);
// 	prev_last = (*stack_b);
// 	while (prev_last->next && prev_last->next->next)
// 		prev_last = prev_last->next;
// 	prev_last->next = NULL;
// 	begin->next = (*stack_b);
// 	(*stack_b) = begin;
// }

void	rev_rotate_b(t_list **stack_b)
{
	t_list	*begin;
	t_list	*prev_last;

	if (*stack_b == NULL || ft_lstsize(*stack_b) == 1)
		return ;
	begin = ft_lstlast(*stack_b);
	prev_last = (*stack_b);
	while (prev_last->next && prev_last->next->next)
		prev_last = prev_last->next;
	prev_last->next = NULL;
	ft_lstadd_front(stack_b, begin);
}

void	rotate_both(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}

void	rev_rotate_both(t_list **stack_a, t_list **stack_b)
{
	rev_rotate_a(stack_a);
	rev_rotate_b(stack_b);
}