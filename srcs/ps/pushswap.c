/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:03:25 by lramard           #+#    #+#             */
/*   Updated: 2019/02/21 16:02:33 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//choix de l'algo
void	ft_distri(int arc, char **argv)
{
	if (arc <= 5)
	{
		ft_quicksort_min();
	}
	else if (arc <=20)
	{
		ft_quicksort_med();
	}
	else
	{
		ft_quicksort_max();
	}
	ft_printf("\033[32mOK\033[37m\n");
}

void	ft_send(int k)
{
	if(k == 1)
		write(1, "sa", 2);
	else if (k == 2)
		write(1, "sb", 2);
	else if (k == 3)
		write(1, "ss", 2);
	else if (k == 4)
		write(1, "pa", 2);
	else if (k == 5)
		write(1, "pb", 2);
	else if (k == 6)
		write(1, "ra", 2);
	else if (k == 7)
		write(1, "rb", 2);
	else if (k == 8)
		write(1, "rr", 2);
	else if (k == 9)
		write(1, "rra", 3);
	else if (k == 10)
		write(1, "rrb", 3);
	else if (k == 11)
		write(1, "rrr", 3);
	else
		write(1, "KO", 2);
}

//resolution
// on adapte le tri rapid a foncitonner avec les isntructions de push swap 

//tri rapide
int size = ft_length(tableau);

int quicksort(int *tableau,int size)
{
	int i;
	int pvt;
	int mur;
	int tmp;
	if (size < 2)
		return (0);
	pvt = tableau[size - 1];
	mur = 0;
	i = 0;
	while (i < size)
	{
		if(tableau[i] <= pvt)
		{
			if(mur != i){
				tmp = tableau[i];
				tableau[i] = tableau[mur];
				tableau[mur] = tmp;
			}
			mur++;
		}
		i++;
	}
	quicksort(tableau, mur - 1);
	quicksort(tableau + mur - 1, size - mur + 1);
}

//division vis a vis d'un pivot

int		ft_sort3(list)
{
	//trie sur 3 elemetns
	if (top > bottom)
	{
		//inserviosn top et bottom
		ft_send(sa)
	}
	on avance on elements suivant
	ft_send(ra)
	if(top >bottom)
	{
		//inserviosn top et bottom
		ft_send(sa)
	}
	on remet leselements 
	ft_send(rra)
}

int		ft_pivot(list, size)
{
	new list2;
	//calcul d'une mediane ?
	//return la valeur de la mediane
	if (list != vide)
	{
		list2=ft_fusionsort(list);
	}
	while ( i < size)
	{
		elem=elem->next;
	}
	mediane = elemen;
	return (mediane);
}

int main(list)
{
	while (list *a > 3 elements)
	{
		//calcule la mediane et mettr eles elements les plus petits sur a stack b
	}
	if ( list *a == 3)
	{
		//tri de la liste
	}
	
}













int		ft_start