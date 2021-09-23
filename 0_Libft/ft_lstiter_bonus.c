#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*list_ptr;

	if (!lst)
		return ;
	list_ptr = lst;
	while (list_ptr)
	{
		(*f)(list_ptr->content);
		list_ptr = list_ptr;
	}
}
