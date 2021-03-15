#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>
# include "utils.h"


void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_both(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rev_rotate_a(t_list **stack_a);
void	rev_rotate_b(t_list **stack_b);
void	rotate_both(t_list **stack_a, t_list **stack_b);
void	rev_rotate_both(t_list **stack_a, t_list **stack_b);


#endif