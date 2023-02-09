/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:03:32 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/09 17:45:40 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

t_psw_list	*create_list(char **argv)
{
	t_psw_list	*list_start;

	list_start = psw_lstnew(ft_atoi(*argv));
	argv++;
	while (*argv != NULL)
	{
		psw_lstadd_back(&list_start, psw_lstnew(ft_atoi(*argv)));
		argv++;
	}
	return (list_start);
}

void	pb(t_psw_list **a_list, t_psw_list **b_list)
{
	t_psw_list	*tmp;

	tmp = (*a_list)->next;
	psw_lstadd_front(b_list, a_list);
	*a_list = tmp;
}

void update_position(t_psw_list *a_list, t_psw_list *b_list)
{
	int		i;

	i = 1;
	while (a_list != NULL)
	{
		a_list->index = i;
		a_list = a_list->next;
		i++;
	}
	i = 1;
	while (b_list != NULL)
	{
		b_list->index = i;
		b_list = b_list->next;
		i++;
	}
}

int main(int argc, char **argv)
{
	t_psw_list *a_list;
	t_psw_list *b_list;

//#linked list erstellen
	a_list = create_list(argv + 1);
//#zwei nach B schieben
	pb(&a_list, &b_list);
	pb(&a_list, &b_list);
//#positionsinfo beider stacks aktuallisieren
	update_position(a_list, b_list);




//Print stacks:
	printf("STACK A:\n");
	printf("%i\n", a_list->content);
	printf("index:%i\n", a_list->index);
		while(a_list->next != NULL)
	{
		a_list = a_list->next;
		
		printf("%i\n", a_list->content);
		printf("index:%i\n", a_list->index);
	}

	printf("STACK B:\n");
	printf("%i\n", b_list->content);
	printf("index:%i\n", b_list->index);
	while(b_list->next != NULL)
	{
		b_list = b_list->next;
		
		printf("%i\n", b_list->content);
		printf("index:%i\n", b_list->index);
	}
	


	/*
		#linked list erstellen
		#zwei nach B schieben

		#positionsinfo beider stacks aktuallisieren
	
	Kosten berechnen
	#A: berechnen ob ra oder rra kurzer ist.
	#B: berechnen ob rb oder rrb kurzer ist.
	#berechnen, welche kombination am wenigsten kostet (ra, ra)

	# die günstigste Zahl aus A nehmen und eneut günstigste kombination berechnen 
	#Rotation und swap durchführen
	#befehl printen

	# wieder starten bei positionsinfo aktuallisieren bis A nur noch drei werte hat

	# drei werte in A sortieren

	#schauen welcher wert der nächste kleinere unter dem ersten B wert ist
	# A rotieren
	#swab B zu A
	*/
}