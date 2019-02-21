#include <ft_push_swap.h>
#include <stdlib.h>

t_checke	*ft_sortedmerge(t_checke *a, t_checke *b)
{
	t_checke *result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->n <= b->n)
	{
		result = a;
		result->next = ft_sortedmerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = ft_sortedmerge(a, b->next);
	}
	return (result);
}

void	ft_frontbacksplit(t_checke *source, t_checke **frontref,
	t_checke **backref)
{
	t_checke *fast;
	t_checke *slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*frontref = source;
	*backref = slow->next;
	slow->next = NULL;
}

void	ft_mergesort(t_checke **headref)
{
	t_checke *head;
	t_checke *a;
	t_checke *b;

	head = *headref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	ft_frontbacksplit(head, &a, &b);
	ft_mergesort(&a);
	ft_mergesort(&b);
	*headref = ft_sortedmerge(a, b);
}

void	ft_printlist(t_checke *node)
{
	while (node != NULL)
	{
		ft_printf("%d ", node->n);
		node = node->next;
	}
}

void	ft_push(t_checke **head_ref, int new_data)
{
	t_checke *new_node;

	new_node = (t_checke*)malloc(sizeof(t_checke));
	new_node->n = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
