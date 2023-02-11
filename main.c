/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:03:32 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/11 17:37:05 by chris            ###   ########.fr       */
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



t_psw_list	*find_node_b(int content_a, t_psw_list *b_list)
{
	int			max_content;
	int			max_max_content;
	t_psw_list	*max_node;
	t_psw_list	*max_max_node;

	max_content = 0;
	max_max_content = 0;
	while (b_list != NULL)
	{
		if (b_list->content > max_max_content)
		{
			max_max_content = b_list->content;
			max_max_node = b_list;
		}
		if (b_list->content < content_a && b_list->content > max_content)
		{
			max_content = b_list->content;
			max_node = b_list;
		}
		b_list = b_list->next;
	}
	if (max_content == 0)
		return (max_max_node);
	return (max_node);
}

void	clear_values(t_psw_list *lst)
{
	while (lst != NULL)
	{
		lst->costs = 0;
		lst->ra = 0;
		lst->rra = 0;
		lst->rb = 0;
		lst->rrb = 0;
		lst->rr = 0;
		lst->rrr = 0;
		lst->node_b = NULL;
		lst = lst->next;
	}
}

void	update_lists(t_psw_list *a_list, t_psw_list *b_list)
{
	int		i;

	i = 1;
	clear_values(a_list);
	clear_values(b_list);

	while (a_list != NULL)
	{
		a_list->index = i;
		a_list->node_b = find_node_b(a_list->content, b_list);
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



void	rx_rrx_costs(t_psw_list *a_list, t_psw_list *b_list)
{
	t_psw_list	*a_list_start;

	a_list_start = a_list;
	while (a_list != NULL)
	{
		if (a_list->index - 1 <= (psw_lstsize(a_list_start) - a_list->index + 1))   // Am ende prüfen, ob die +1 weggelassen werden kann. müsste eigentlich.
		{
			//printf("hallo");
			a_list->ra = a_list->index - 1;
		}
		else
		{
			//printf("olla:%i", psw_lstsize(a_list_start));
			a_list->rra = psw_lstsize(a_list_start) - a_list->index + 1;
		}
		if (a_list->node_b->index - 1 < (psw_lstsize(b_list) - a_list->node_b->index + 1))
			a_list->rb = a_list->node_b->index - 1;
		else
		{
			a_list->rrb = psw_lstsize(b_list) - a_list->node_b->index + 1;
		}
		a_list->costs = a_list->ra + a_list->rra + a_list->rb + a_list->rrb + a_list->rr + a_list->rrr;
		a_list = a_list->next;
	}
}

t_psw_list	*cheapest_node(t_psw_list *a_list, t_psw_list *b_list)
{
	t_psw_list	*cheapest;
	int			min_costs;

	
	//#A: berechnen ob ra oder rra kurzer ist.
	//#B: berechnen ob rb oder rrb kurzer ist.
	//# Kosten A & B addieren.
	rx_rrx_costs(a_list, b_list);

	min_costs = a_list->costs;
	cheapest = a_list;
	while (a_list != NULL)
	{
		if (a_list->costs < min_costs)
		{
			min_costs = a_list->costs;
			cheapest = a_list;
		}
		a_list = a_list->next;
	}
	return (cheapest);
}


void	run_rotate(t_psw_list **a_list, t_psw_list **b_list, int amount_rotate, void (*f)(t_psw_list **, t_psw_list **))
{
	while (amount_rotate > 0)
	{
		f(a_list, b_list);
		amount_rotate--;
	}
}

void	rotate_all(t_psw_list **a_list, t_psw_list **b_list, t_psw_list *node_a_to_push)
{
	run_rotate(a_list, b_list, node_a_to_push->ra, &ra);
	run_rotate(a_list, b_list, node_a_to_push->rra, &rra);
	run_rotate(a_list, b_list, node_a_to_push->rb, &rb);
	run_rotate(a_list, b_list, node_a_to_push->rrb, &rrb);
	run_rotate(a_list, b_list, node_a_to_push->rr, &rr);
	run_rotate(a_list, b_list, node_a_to_push->rrr, &rrr);
}


void	sort_three(t_psw_list **a_list)
{
	int			max_max_content;
	t_psw_list	*max_max_node;
	t_psw_list	*a_list_start;

	a_list_start = *a_list;
	while (*a_list != NULL)
	{
		if ((*a_list)->content > max_max_content)
		{
			max_max_content = (*a_list)->content;
			max_max_node = *a_list;
		}
		*a_list = (*a_list)->next;
	}
	*a_list = a_list_start;
	if (max_max_node->index == 3
		&& (*a_list)->content < (*a_list)->next->content)
		exit(0);
	if (max_max_node->index == 1)
		ra(a_list, NULL);
	if (max_max_node->index == 2)
		rra(a_list, NULL);
	if ((*a_list)->content > (*a_list)->next->content)
		sa(*a_list);
}

int main(int argc, char **argv)
{
	t_psw_list	*a_list;
	t_psw_list	*b_list;
	t_psw_list	*node_a_to_push;

//#linked list erstellen
	a_list = create_list(argv + 1);
//#zwei nach B schieben
	pb(&a_list, &b_list);
	pb(&a_list, &b_list);


	while (psw_lstsize(a_list) > 3)
	{
	//#positionsinfo beider stacks aktuallisieren
		update_lists(a_list, b_list);
	//Kosten berechnen
		node_a_to_push = cheapest_node(a_list, b_list);
	//#Rotation und swap  mit der günstigsten Zahl durchführen
	//#befehl printen
		rotate_all(&a_list, &b_list, node_a_to_push);
		pb(&a_list, &b_list);
	//# wieder starten bei positionsinfo aktuallisieren bis A nur noch drei werte hat
		printf("push:%i\n", b_list->content);
		//update_lists(a_list, b_list);
		////node_a_to_push = cheapest_node(a_list, b_list);
		//if (b_list->content == 8)
		//	break;
	}

//# positionsinfo updaten und drei werte in A sortieren
	update_lists(a_list, b_list);
	sort_three(&a_list);

//Print stacks:
	printf("STACK A:\n");
	printf("%i index:%i costs:%i ra:%i rra:%i rb:%i rrb:%i rr:%i rrr:%i content_b:%i\n", a_list->content, a_list->index, a_list->costs, a_list->ra, a_list->rra, a_list->rb, a_list->rrb, a_list->rr, a_list->rrr, a_list->node_b->content);
	while(a_list->next != NULL)
	{
		a_list = a_list->next;
		
		printf("%i index:%i costs:%i ra:%i rra:%i rb:%i rrb:%i rr:%i rrr:%i content_b:%i\n", a_list->content, a_list->index, a_list->costs, a_list->ra, a_list->rra, a_list->rb, a_list->rrb, a_list->rr, a_list->rrr, a_list->node_b->content);
	}

	printf("STACK B:\n");
	printf("%i index:%i costs:%i ra:%i rra:%i rb:%i rrb:%i rr:%i rrr:%i\n", b_list->content, b_list->index, b_list->costs, b_list->ra, b_list->rra, b_list->rb, b_list->rrb, b_list->rr, b_list->rrr);
	while(b_list->next != NULL)
	{
		b_list = b_list->next;
		
		printf("%i index:%i costs:%i ra:%i rra:%i rb:%i rrb:%i rr:%i rrr:%i\n", b_list->content, b_list->index, b_list->costs, b_list->ra, b_list->rra, b_list->rb, b_list->rrb, b_list->rr, b_list->rrr);
	}
	printf("node_a_to_push_index:%i\n", node_a_to_push->index);


	/*
		#linked list erstellen
		#zwei nach B schieben

		#positionsinfo beider stacks aktuallisieren
		# Note in B finden über den A hinzugefügt werden muss
	
	Kosten berechnen
		#A: berechnen ob ra oder rra kurzer ist.
		#B: berechnen ob rb oder rrb kurzer ist.
		# Kosten A & B addieren.
	#berechnen, ob durch rr oder rrr kosten reduziert werden können:
	#größerer index sind die max kosten. (rr+rX)
	#größerer (list len - index) sind die max kosten (rrr+rrX).

		#Rotation und swap mit der günstigsten Zahl durchführen
		#befehl printen

		# wieder starten bei positionsinfo aktuallisieren bis A nur noch drei werte hat

		# drei werte in A sortieren

	#schauen welcher wert der nächste kleinere unter dem ersten B wert ist
	# A rotieren
	#swab B zu A
	*/
}