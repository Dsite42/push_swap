/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:03:32 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/08 19:00:45 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

t_psw_list *create_list(char **argv)
{
	t_psw_list *list_start;

	list_start = psw_lstnew(ft_atoi(*argv));
	argv++;
	while (argv != NULL)
	{
		psw_lstadd_back(&list_start, psw_lstnew(ft_atoi(*argv)));
	}
	return (list_start);
}

int main(int argc, char **argv)
{
	printf("%i", create_list(argv+1)->content);
	


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