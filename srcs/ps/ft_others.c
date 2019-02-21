#include <ft_push_swap.h>

void	ft_error(t_checke *p)
{
	write(2, "\033[31mError\033[37m\n", 17);
	free(p->next);
	exit(0);
}

int		ft_lstl(t_checke *list)
{
	int		j;

	if (list)
	{
		j = 0;
		while (list)
		{
			list = list->next;
			j++;
		}
		return (j);
	}
	else
		return (0);
}
