#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *str);
void	ra(t_list **a);
void	sa(t_list **a);
void	rra(t_list **a);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);