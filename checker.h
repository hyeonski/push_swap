#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

#endif