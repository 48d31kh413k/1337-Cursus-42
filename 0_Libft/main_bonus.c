#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
# define TRUE 1
# define FALSE 0
# define ANSI_RED "\x1b[31m" 
# define ANSI_GREEN "\x1b[32m" 
# define ANSI_YELLOW "\x1b[33m" 
# define ANSI_BLUE "\x1b[34m" 
# define ANSI_MAGENTA "\x1b[35m" 
# define ANSI_CYAN "\x1b[36m" 
# define ANSI_RESET  "\x1b[0m"
# define STDOUT 1

static void	listfree(t_list *list)
{
	t_list	*current;
	t_list	*tmp;

	current = list;
	while (current != NULL)
	{
		free(current->content);
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

static char	lstadd_back_test(t_list *list, const char *expected)
{
	t_list	*last;
	int		diff;

	last = ft_lstlast(list);
	diff = strcmp(last->content, expected);
/*
	printf("content  is %s\n", (char *)last->content);
	printf("expected is %s\n", expected);
*/
	if (last->next == NULL && diff == 0)
		return ('Y');
	else
		return ('N');
}

static char	lstadd_front_test(t_list *list, const char *expected)
{
	int	diff;

	diff = strcmp(list->content, expected);
/*
	printf("content  is %s\n", (char *)list->content);
	printf("expected is %s\n", expected);
*/
	if (diff == 0)
		return ('Y');
	else
		return ('N');
}

static char lstclear_test(t_list *a)
{
	if (a == NULL)
		return ('Y');
	else
		return ('N');
}

static char lstclear_test1(t_list *a)
{
	if (a)
		return ('N');
	else
		return ('Y');
}

static void	lstdelone_test(t_list *list)
{
	t_list	*current;
	t_list	*next;
	int		i;

	i = 1;
	current = list;
	while (current != NULL)
	{	
		next = current->next;
		printf("content  is %s\n", (char *)current->content);
		ft_lstdelone(current, free);
		current = next;
		printf("list[%d] is deleted\n", i);
		i++;
	}
}


int main()
{

	char	*test_lstadd_back;
	char	*test_lstadd_front;
	char	*test_lstclear;
	char	*test_lstdelone;
	t_list	*list;
	t_list	*list1;
	t_list	*new;
	t_list	*new1;
	t_list	*list3;
	t_list	*new3;
	t_list	*list2;
	t_list	*new2;

	int	j = 0;
	int	k = 0;
	int	i;






	test_lstadd_back = (char *)malloc(sizeof(char) * 4);
	test_lstadd_front = (char *)malloc(sizeof(char) * 4);
	test_lstclear = (char *)malloc(sizeof(char) * 2);
	test_lstdelone = (char *)malloc(sizeof(char) * 2);







	list = NULL;
	new = ft_lstnew(strdup("one"));
	ft_lstadd_back(&list, new);
	test_lstadd_back[0] = lstadd_back_test(list, "one");
	new = ft_lstnew(strdup("two"));
	ft_lstadd_back(&list, new);
	test_lstadd_back[1] = lstadd_back_test(list, "two");
	new = ft_lstnew(strdup("three"));
	ft_lstadd_back(&list, new);
	test_lstadd_back[2] = lstadd_back_test(list, "three");
	test_lstadd_back[3] = '\0';
	listfree(list);



	list1 = NULL;
	new1 = ft_lstnew(strdup("one"));
	ft_lstadd_front(&list1, new1);
	test_lstadd_front[0] = lstadd_front_test(list1, "one");
	new1 = ft_lstnew(strdup("two"));
	ft_lstadd_front(&list1, new1);
	test_lstadd_front[1] = lstadd_front_test(list1, "two");
	new1 = ft_lstnew(strdup("three"));
	ft_lstadd_front(&list1, new1);
	test_lstadd_front[2] = lstadd_front_test(list1, "three");
	test_lstadd_front[3] = '\0';
	listfree(list1);


	list3 = NULL;
	new3 = ft_lstnew(strdup("o"));
	ft_lstadd_back(&list3, new3);
	printf("%s\n", (char *)list3->content);
	ft_lstclear(&list3, free);
	test_lstclear[0] = lstclear_test(list3);
	test_lstclear[1] = '\0';


	list2 = NULL;
	new2 = ft_lstnew(strdup("one"));
	ft_lstadd_back(&list2, new2);
	new2 = ft_lstnew(strdup("two"));
	ft_lstadd_back(&list2, new2);
	new2 = ft_lstnew(strdup("three"));
	ft_lstadd_back(&list2, new2);
	lstdelone_test(list2);
	test_lstdelone[0] = lstclear_test1(list2);
	test_lstdelone[1] = '\0';
	




	printf(ANSI_BLUE "\n********** LIBFT  BONUS TESTER **********\n\n");
	printf(ANSI_BLUE " ---------------- \n");
	printf("| ft_lstadd_back |\n");
	printf(" ---------------- \n");
	for(i = 0; i < 3; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_lstadd_back[i]);
	i = 0;
	while(test_lstadd_back[i])
	{
		if (test_lstadd_back[i] == 'N')
		{	printf(ANSI_RED "ft_lstadd_back : KO\n");
			break;
		}
		i++;
	}

	if (test_lstadd_back[i] == '\0')
	{
		printf(ANSI_GREEN "ft_lstadd_back : OK\n");
		j++;
	}
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ----------------- \n");
	printf("| ft_lstadd_front |\n");
	printf(" ----------------- \n");
	for(i = 0; i < 3; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_lstadd_front[i]);
	i = 0;
	while(test_lstadd_front[i])
	{
		if (test_lstadd_front[i] == 'N')
		{	printf(ANSI_RED "ft_lstadd_front : KO\n");
			break;
		}
		i++;
	}

	if (test_lstadd_front[i] == '\0')
	{
		printf(ANSI_GREEN "ft_lstadd_front : OK\n");
		j++;
	}
	k++;	
	printf("\n");	
	printf(ANSI_BLUE " ------------- \n");
	printf("| ft_lstclear |\n");
	printf(" ------------- \n");
	for(i = 0; i < 1; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_lstclear[i]);
	i = 0;
	while(test_lstclear[i])
	{
		if (test_lstclear[i] == 'N')
		{	printf(ANSI_RED "ft_lstclear : KO\n");
			break;
		}
		i++;
	}

	if (test_lstclear[i] == '\0')
	{
		printf(ANSI_GREEN "ft_lstclear : OK\n");
		j++;
	}
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ------------- \n");
	printf("| ft_lstdelone |\n");
	printf(" ------------- \n");
	for(i = 0; i < 1; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_lstdelone[i]);
	i = 0;
	while(test_lstdelone[i])
	{
		if (test_lstdelone[i] == 'N')
		{	printf(ANSI_RED "ft_lstdelone : KO\n");
			break;
		}
		i++;
	}

	if (test_lstdelone[i] == '\0')
	{
		printf(ANSI_GREEN "ft_lstdelone : OK\n");
		j++;
	}
	k++;	
	printf("\n");











	printf(ANSI_YELLOW "TOTAL = %d functions\n", k);

	if (j == k)
		printf(ANSI_GREEN "LIBFT ==> OK\n");
	else
	 	printf(ANSI_RED "LIBFT ==> KO\n");
	printf(ANSI_GREEN"CORRECT : %d \n", j); 
	printf(ANSI_RED"FALSE : %d \n", (k-j));
	return (0);
}
