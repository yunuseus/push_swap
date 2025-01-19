#include <stdio.h>
#include "libft/libft.h"
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int	ft_atoi(const char *str);
void ra(int *a, int len);
void sa(int *a, int len);
void rra(int *a, int len);
int ft_lstlast(t_list *lst);
