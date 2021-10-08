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
		//printf("content  is %s\n", (char *)current->content);
		ft_lstdelone(current, free);
		current = next;
		//printf("list[%d] is deleted\n", i);
		i++;
	}
}

static void	my_toupper(void *content)
{
	int		i;
	char	*copy;

	if (content == NULL)
		return ;
	copy = (char *)content;
	i = 0;
	while (copy[i] != '\0')
	{
		if (copy[i] >= 'a' && copy[i] <= 'z')
			copy[i] -= 32;
		i++;
	}
}


static char	lstiter_test(t_list *element, const char *expected)
{
	int		diff;

	diff = strcmp(element->content, expected);
/*
	printf("content  is %s\n", element->content);
	printf("expected is %s\n", expected);
*/
	if (diff == 0)
		return ('Y');
	else
		return ('N');
}

static char	lstlast_test(t_list *list, const char *expected)
{
	t_list	*last;
	int		diff;

	last = ft_lstlast(list);
	diff = strcmp(last->content, expected);
/*
	printf("content  is %s\n", last->content);
	printf("expected is %s\n", expected);
*/
	if (last->next == NULL && diff == 0)
		return ('Y');
	else
		return ('N');
}

static void	*my_toupper1(void *content)
{
	char	*ret;
	char	*copy;
	int		i;

	if (content == NULL)
		return (NULL);

	copy = (char *)content;
	ret = (char *)malloc(sizeof(char) * (strlen(copy) + 1));
	if (ret == NULL)
		return (NULL);

	i = 0;
	while (copy[i] != '\0')
	{
		if (copy[i] >= 'a' && copy[i] <= 'z')
			ret[i] = copy[i] - ('a' - 'A');
		else
			ret[i] = copy[i];
		i++;
	}
	return (ret);
}

static char	lstmap_test(t_list *element, const char *expected)
{
	int		diff;

	diff = strcmp(element->content, expected);
/*
	printf("content  is %s\n", element->content);
	printf("expected is %s\n", expected);
*/
	if (diff == 0)
		return ('Y');
	else
		return ('N');
}

static char	lstnew_test(t_list *latest, const char *expected)
{
	int		diff;

	diff = strcmp(latest->content, expected);
/*
	printf("content  is %s\n", latest->content);
	printf("expected is %s\n", expected);
*/
	if (latest->next == NULL && diff == 0)
		return ('Y');
	else
		return ('N');
}

static char	lstsize_test(t_list *list, int	expected_size)
{
/*
	printf("func return size is %d\n", ft_lstsize(list));
	printf("expected size    is %d\n", expected_size);
*/
	if (ft_lstsize(list) == expected_size)
		return ('Y');
	else
		return ('N');
}


int main()
{

	char	*test_lstadd_back;
	char	*test_lstadd_front;
	char	*test_lstclear;
	char	*test_lstdelone;
	char	*test_lstiter;
	char	*test_lstlast;
	char	*test_lstmap;
	char	*test_lstnew;
	char	*test_lstsize;
	t_list	*list;
	t_list	*list1;
	t_list	*new;
	t_list	*new1;
	t_list	*list3;
	t_list	*new3;
	t_list	*list2;
	t_list	*new2;
	t_list	*list4;
	t_list	*new4;
	t_list	*list5;
	t_list	*new5;
	t_list	*list6;
	t_list	*list7;
	t_list	*new6;
	t_list	*list8;
	t_list	*new8;
	t_list	*list9;
	t_list	*new9;


	int	j = 0;
	int	k = 0;
	int	i;






	test_lstadd_back = (char *)malloc(sizeof(char) * 4);
	test_lstadd_front = (char *)malloc(sizeof(char) * 4);
	test_lstclear = (char *)malloc(sizeof(char) * 2);
	test_lstdelone = (char *)malloc(sizeof(char) * 2);
	test_lstiter = (char *)malloc(sizeof(char) * 4);
	test_lstlast = (char *)malloc(sizeof(char) * 4);
	test_lstmap = (char *)malloc(sizeof(char) * 4);
	test_lstnew = (char *)malloc(sizeof(char) * 4);
	test_lstsize = (char *)malloc(sizeof(char) * 4);






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
	//listfree(list1);


	list3 = NULL;
	new3 = ft_lstnew(strdup("o"));
	ft_lstadd_back(&list3, new3);
	ft_lstclear(&list3, free);
	test_lstclear[0] = lstclear_test(list3);
	test_lstclear[1] = '\0';
	//listfree(list3);


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
	//listfree(list2);

	

	list4 = NULL;
	new4 = ft_lstnew(strdup("one"));
	ft_lstadd_back(&list4, new4);
	new4 = ft_lstnew(strdup("two"));
	ft_lstadd_back(&list4, new4);
	new4 = ft_lstnew(strdup("three"));
	ft_lstadd_back(&list4, new4);
	ft_lstiter(list4, &my_toupper);
	test_lstiter[0] = lstiter_test(list4, "ONE");
	test_lstiter[1] = lstiter_test(list4->next, "TWO");
	test_lstiter[2] = lstiter_test(list4->next->next, "THREE");
	test_lstiter[3] = '\0';
	//listfree(list4);


	

	list5 = NULL;
	new5 = ft_lstnew(strdup("one"));
	list5 = new5;
	test_lstlast[0] = lstlast_test(list5, "one");
	new5 = ft_lstnew(strdup("two"));
	list5->next = new5;
	test_lstlast[1] = lstlast_test(list5, "two");
	new5 = ft_lstnew(strdup("three"));
	list5->next->next = new5;
	test_lstlast[2] = lstlast_test(list5, "three");
	test_lstlast[3] = '\0';
	//listfree(list5);



	list6 = NULL;
	new6 = ft_lstnew(strdup("one"));
	ft_lstadd_back(&list6, new6);
	new6 = ft_lstnew(strdup("two"));
	ft_lstadd_back(&list6, new6);
	new6 = ft_lstnew(strdup("three"));
	ft_lstadd_back(&list6, new6);
	list7 = ft_lstmap(list6, &my_toupper1, free);
	test_lstmap[0] = lstmap_test(list7, "ONE");
	test_lstmap[1] = lstmap_test(list7->next, "TWO");
	test_lstmap[2] = lstmap_test(list7->next->next, "THREE");
	test_lstmap[3] = '\0';
	//listfree(list6);
	//listfree(list7);




	list8 = NULL;
	list8 = ft_lstnew(strdup("one"));
	test_lstnew[0] = lstnew_test(list8, "one");
	new8 = ft_lstnew(strdup("two"));
	list8->next = new8;
	test_lstnew[1] = lstnew_test(list8->next, "two");
	new8 = ft_lstnew(strdup("three"));
	list8->next->next = new8;
	test_lstnew[2] = lstnew_test(list8->next->next, "three");
	test_lstnew[3] = '\0';
	//listfree(list8);



	list9 = NULL;
	new9 = ft_lstnew(strdup("one"));
	list9 = new9;
	test_lstsize[0] = lstsize_test(list9, 1);
	new9 = ft_lstnew(strdup("two"));
	list9->next = new9;
	test_lstsize[1] = lstsize_test(list9, 2);
	new9 = ft_lstnew(strdup("three"));
	list9->next->next = new9;
	test_lstsize[2] = lstsize_test(list9, 3);
	test_lstsize[3] = '\0';
	//listfree(list9);




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
	printf(ANSI_BLUE " -------------- \n");
	printf("| ft_lstdelone |\n");
	printf(" -------------- \n");
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
	printf(ANSI_BLUE " ------------- \n");
	printf("| ft_lstiter |\n");
	printf(" ------------- \n");
	for(i = 0; i < 3; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_lstiter[i]);
	i = 0;
	while(test_lstiter[i])
	{
		if (test_lstiter[i] == 'N')
		{	printf(ANSI_RED "ft_lstiter : KO\n");
			break;
		}
		i++;
	}

	if (test_lstiter[i] == '\0')
	{
		printf(ANSI_GREEN "ft_lstiter : OK\n");
		j++;
	}
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ------------- \n");
	printf("| ft_lstlast |\n");
	printf(" ------------- \n");
	for(i = 0; i < 3; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_lstlast[i]);
	i = 0;
	while(test_lstlast[i])
	{
		if (test_lstlast[i] == 'N')
		{	printf(ANSI_RED "ft_lstlast : KO\n");
			break;
		}
		i++;
	}

	if (test_lstlast[i] == '\0')
	{
		printf(ANSI_GREEN "ft_lstlast : OK\n");
		j++;
	}
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ------------- \n");
	printf("| ft_lstmap |\n");
	printf(" ------------- \n");
	for(i = 0; i < 3; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_lstmap[i]);
	i = 0;
	while(test_lstmap[i])
	{
		if (test_lstmap[i] == 'N')
		{	printf(ANSI_RED "ft_lstmap : KO\n");
			break;
		}
		i++;
	}

	if (test_lstmap[i] == '\0')
	{
		printf(ANSI_GREEN "ft_lstmap : OK\n");
		j++;
	}
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ------------- \n");
	printf("| ft_lstnew |\n");
	printf(" ------------- \n");
	for(i = 0; i < 3; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_lstnew[i]);
	i = 0;
	while(test_lstnew[i])
	{
		if (test_lstnew[i] == 'N')
		{	printf(ANSI_RED "ft_lstnew : KO\n");
			break;
		}
		i++;
	}

	if (test_lstnew[i] == '\0')
	{
		printf(ANSI_GREEN "ft_lstnew : OK\n");
		j++;
	}
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ------------- \n");
	printf("| ft_lstsize |\n");
	printf(" ------------- \n");
	for(i = 0; i < 3; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_lstsize[i]);
	i = 0;
	while(test_lstsize[i])
	{
		if (test_lstsize[i] == 'N')
		{	printf(ANSI_RED "ft_lstnew : KO\n");
			break;
		}
		i++;
	}

	if (test_lstsize[i] == '\0')
	{
		printf(ANSI_GREEN "ft_lstsize : OK\n");
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
