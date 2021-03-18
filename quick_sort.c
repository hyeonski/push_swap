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
	// printf("sa\n");
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
	// printf("sb\n");
}

void	swap_both(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	// printf("sb\n");
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list *begin;

	if (*stack_b == NULL)
		return ;
	begin = (*stack_b)->next;
	(*stack_b)->next = NULL;
	(*stack_b)->prev = NULL;
	ft_lstadd_front(stack_a, (*stack_b));
	*stack_b = begin;
	if (*stack_b != NULL)
		(*stack_b)->prev = NULL;
	// printf("pa\n");
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list *begin;

	if (*stack_a == NULL)
		return ;
	begin = (*stack_a)->next;
	// int *temp;
	// temp = begin->content;
	// printf("temp: %d\n", *temp);
	(*stack_a)->next = NULL;
	(*stack_a)->prev = NULL;
	ft_lstadd_front(stack_b, (*stack_a));
	*stack_a = begin;
	if (*stack_a != NULL)
		(*stack_a)->prev = NULL;
	// printf("pb\n");
}

void	rotate_a(t_list **stack_a)
{
	t_list	*temp;

	if (*stack_a == NULL || ft_lstsize(*stack_a) == 1)
		return ;
	temp = *stack_a;
	(*stack_a) = (*stack_a)->next;
	temp->next = NULL;
	ft_lstadd_back(stack_a, temp);
	(*stack_a)->prev = NULL;
	// printf("ra\n");
}

void	rotate_b(t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b == NULL || ft_lstsize(*stack_b) == 1)
		return ;
	temp = *stack_b;
	(*stack_b) = (*stack_b)->next;
	temp->next = NULL;
	ft_lstadd_back(stack_b, temp);
	(*stack_b)->prev = NULL;
	// printf("rb\n");
}

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
	begin->prev = NULL;
	// printf("rra\n");

}

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
	begin->prev = NULL;
	// printf("rrb\n");
}

void	rotate_both(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	// printf("rr\n");
}

void	rev_rotate_both(t_list **stack_a, t_list **stack_b)
{
	rev_rotate_a(stack_a);
	rev_rotate_b(stack_b);
	// printf("rrr\n");
}

int	cmp_element(int *a, int *b)
{
	return (*a - *b);
}

void	print_list(t_list *list)
{
	if (list == NULL)
	{
		printf("empty\n");
		return ;
	}
	while (list)
	{
		int *p = list->content;
		printf("%d\n", *p);
		list = list->next;
	}
}



int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	argv++;
	while (*argv)
	{
		int temp = atoi(*argv);
		int *p = malloc(sizeof(int));
		*p = temp;
		ft_lstadd_back(&stack_a, ft_lstnew(p));
		argv++;
	}
	a_to_b(ft_lstsize(stack_a), cmp_element, &stack_a, &stack_b);
	printf("stack a:\n");
	print_list(stack_a);
	printf("stack b:\n");
	print_list(stack_b);
}