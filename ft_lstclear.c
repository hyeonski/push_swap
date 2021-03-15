#include "utils.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*curr;

	if (*lst == NULL)
		return ;
	curr = *lst;
	while (curr)
	{
		temp = curr->next;
		del(curr->content);
		free(curr);
		curr = temp;
	}
	*lst = NULL;
}
