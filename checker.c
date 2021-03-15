#include "checker.h"
#include "get_next_line.h"
#include "utils.h"

int	check_duplicate(int val, t_list *stack_a)
{
	int	*temp;
	
	if (stack_a == NULL)
		return (1);
	while (stack_a)
	{
		temp = stack_a->content;
		if (*temp == val)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	init(t_list **stack_a, t_list **stack_b, char **argv)
{
	int	*val;

	*stack_a = NULL;
	*stack_b = NULL;
	argv++;
	while (*argv)
	{
		if (!(is_str_digit(*argv) && is_str_int_range(*argv)))
			return (0);
		val = alloc_int(ft_atoi(*argv));
		if (val == NULL)
			return (0);
		if (check_duplicate(*val, *stack_a) == 0)
		{
			free(val);
			return (0);
		}
		ft_lstadd_back(stack_a, ft_lstnew(val));
		argv++;
	}
	return (1);
}

int	do_operation(t_list **stack_a, t_list **stack_b, char *op)
{
	if (ft_strcmp(op, "sa") == 0)
		swap_a(stack_a);
	else if (ft_strcmp(op, "sb") == 0)
		swap_b(stack_b);
	else if (ft_strcmp(op, "ss") == 0)
		swap_both(stack_a, stack_b);
	else if (ft_strcmp(op, "pa") == 0)
		push_a(stack_a, stack_b);
	else if (ft_strcmp(op, "pb") == 0)
		push_b(stack_a, stack_b);
	else if (ft_strcmp(op, "ra") == 0)
		rotate_a(stack_a);
	else if (ft_strcmp(op, "rb") == 0)
		rotate_b(stack_b);
	else if (ft_strcmp(op, "rr") == 0)
		rotate_both(stack_a, stack_b);
	else if (ft_strcmp(op, "rra") == 0)
		rev_rotate_a(stack_a);
	else if (ft_strcmp(op, "rrb") == 0)
		rev_rotate_b(stack_b);
	else if (ft_strcmp(op, "rrr") == 0)
		rev_rotate_both(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	check_sorted(t_list *stack_a, t_list *stack_b)
{
	if (stack_b != NULL)
	{
		write(STDOUT_FILENO, "KO\n", 3);
		return ;
	}
	while (stack_a->next)
	{
		if (!(cmp_element(stack_a->content, stack_a->next->content) < 0))
		{
			write(STDOUT_FILENO, "KO\n", 3);
			return ;
		}
		stack_a = stack_a->next;
	}
	write(STDOUT_FILENO, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	char	*op;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	if (init(&stack_a, &stack_b, argv) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		ft_lstclear(&stack_a, free);
		return (0);
	}
	while (get_next_line(STDIN_FILENO, &op))
	{
		if (do_operation(&stack_a, &stack_b, op) == 0)
		{
			write(STDERR_FILENO, "Error\n", 6);
			return (0);
		}
		free(op);
	}
	check_sorted(stack_a, stack_b);
	ft_lstclear(&stack_a, free);
	return (0);
}
