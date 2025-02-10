#include <stdio.h>
#include <stdlib.h>
#include "printf.h"

typedef struct s_nodes
{
	int				content;
	int				index;
	struct s_nodes	*next;
}	t_nodes;

int		ft_atoi(const char *str);
void	ra(t_nodes **a);
void	sa(t_nodes **a);
void	rr(t_nodes **a, t_nodes **b);
void	rra(t_nodes **a, int b);
t_nodes	*ft_lstlast(t_nodes *lst);
void	ft_lstadd_back(t_nodes **lst, t_nodes *new);
t_nodes	*ft_lstnew(int content);
void	ft_lstadd_front(t_nodes **lst, t_nodes *new);
void	ft_lst_free(t_nodes *list);
int		ft_lstsize(t_nodes *lst);
void	pb(t_nodes **a, t_nodes **b);
void	pa(t_nodes **a, t_nodes **b);
int 	ft_check_av(int argc, char **argv);
void	free_argv(char **str);
