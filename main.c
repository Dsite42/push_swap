/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:03:32 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/12 20:02:23 by chris            ###   ########.fr       */
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

t_psw_list	*find_node_a(int content_b, t_psw_list *a_list)
{
	int			min_content;
	int			min_min_content;
	t_psw_list	*min_node;
	t_psw_list	*min_min_node;

	min_content = INT_MAX;
	min_min_content = INT_MAX;
	while (a_list != NULL)
	{
		if (a_list->content < min_min_content)
		{
			min_min_content = a_list->content;
			min_min_node = a_list;
		}
		if (a_list->content > content_b && a_list->content < min_content)
		{
			min_content = a_list->content;
			min_node = a_list;
		}
		a_list = a_list->next;
	}
	if (min_content == INT_MAX)
		return (min_min_node);
	return (min_node);
}


void	clear_node_cost_values(t_psw_list *lst)
{
		lst->costs = 0;
		lst->ra = 0;
		lst->rra = 0;
		lst->rb = 0;
		lst->rrb = 0;
		lst->rr = 0;
		lst->rrr = 0;
}

void	copy_node_cost_values(t_psw_list *lst, t_psw_list *new_values)
{
		lst->costs = new_values->costs;
		lst->ra = new_values->ra;
		lst->rra = new_values->rra;
		lst->rb = new_values->rb;
		lst->rrb = new_values->rrb;
		lst->rr = new_values->rr;
		lst->rrr = new_values->rrr;
}



void	clear_stack_values(t_psw_list *lst)
{
	while (lst != NULL)
	{
		clear_node_cost_values(lst);
		lst->node_b = NULL;
		lst = lst->next;
	}
}

void	update_lists(t_psw_list *a_list, t_psw_list *b_list)
{
	int		i;

	i = 1;

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

void	rr_cost_optimization(t_psw_list *a_list, t_psw_list *b_list)
{
	t_psw_list	*new_costs;

	new_costs = psw_lstnew(a_list->content);
	clear_node_cost_values(new_costs);
	if (a_list->index - 1 > a_list->node_b->index - 1)
	{
		new_costs->costs = a_list->index - 1;
		new_costs->rr = a_list->node_b->index - 1;
		new_costs->ra = new_costs->costs - new_costs->rr;
	}
	else
	{
		new_costs->costs = a_list->node_b->index - 1;
		new_costs->rr = a_list->index - 1;
		new_costs->rb = new_costs->costs - new_costs->rr;
	}
	if (new_costs->costs < a_list->costs)
		copy_node_cost_values(a_list, new_costs);
	free(new_costs);
}

void	rrr_cost_optimization(t_psw_list *a_list, t_psw_list *b_list, t_psw_list *a_list_start)
{
	t_psw_list	*new_costs;

	new_costs = psw_lstnew(a_list->content);
	clear_node_cost_values(new_costs);
	if ((psw_lstsize(a_list_start) - a_list->index + 1) > (psw_lstsize(b_list) - a_list->node_b->index + 1))
	{
		new_costs->costs = (psw_lstsize(a_list_start) - a_list->index + 1);
		new_costs->rrr = (psw_lstsize(b_list) - a_list->node_b->index + 1);
		new_costs->rra = new_costs->costs - new_costs->rrr;
	}
	else
	{
		new_costs->costs = (psw_lstsize(b_list) - a_list->node_b->index + 1);
		new_costs->rrr = (psw_lstsize(a_list_start) - a_list->index + 1);
		new_costs->rrb = new_costs->costs - new_costs->rrr;
	}
	if (new_costs->costs < a_list->costs)
		copy_node_cost_values(a_list, new_costs);
	free(new_costs);
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
		rr_cost_optimization(a_list, b_list);
		rrr_cost_optimization(a_list, b_list, a_list_start);
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
		update_lists(*a_list, *b_list);
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

int	calc_single_index(t_psw_list *a_list, int to_find)
{
	int	i;

	i = 1;
	while (a_list->content != to_find)
	{
		i++;
		a_list = a_list->next;
	}
	return (i);
}

void	swap_all_to_A(t_psw_list **a_list, t_psw_list **b_list)
{
	int			rotate_amount;
	t_psw_list	*insert_before;

	while (*b_list != NULL)
	{
		//print_stacks(*a_list, *b_list);
		insert_before = find_node_a((*b_list)->content, *a_list);
		//printf("insert_before:%i firstA:%i firstB:%i\n", insert_before->content, (*a_list)->content, (*b_list)->content);
//  		if ((*b_list)->content == 999)
//  		{
//  print_stacks(*a_list, *b_list);
//  			return (0);
// 		}
		rotate_amount = calc_single_index(*a_list, insert_before->content) - 1;
		if (rotate_amount <= (psw_lstsize(*a_list) - rotate_amount))
			run_rotate(a_list, b_list, rotate_amount, &ra);
		else
		{
			rotate_amount = psw_lstsize(*a_list) - rotate_amount;
			run_rotate(a_list, b_list, rotate_amount, &rra);
		}
		pa(a_list, b_list);
	}

}


void	print_stacks(t_psw_list *a_list, t_psw_list *b_list)
{
	printf("STACK A:\n");
	while(a_list != NULL)
	{
		//printf("%i index:%i costs:%i ra:%i rra:%i rb:%i rrb:%i rr:%i rrr:%i content_b:%i\n", a_list->content, a_list->index, a_list->costs, a_list->ra, a_list->rra, a_list->rb, a_list->rrb, a_list->rr, a_list->rrr, a_list->node_b->content);
		printf("%i index:%i costs:%i ra:%i rra:%i rb:%i rrb:%i rr:%i rrr:%i\n", a_list->content, a_list->index, a_list->costs, a_list->ra, a_list->rra, a_list->rb, a_list->rrb, a_list->rr, a_list->rrr);
		a_list = a_list->next;
	}

	printf("STACK B:\n");
	while(b_list != NULL)
	{
		printf("%i index:%i costs:%i ra:%i rra:%i rb:%i rrb:%i rr:%i rrr:%i\n", b_list->content, b_list->index, b_list->costs, b_list->ra, b_list->rra, b_list->rb, b_list->rrb, b_list->rr, b_list->rrr);
		b_list = b_list->next;
	}
	
}

void	rotate_to_min(t_psw_list **a_list, t_psw_list **b_list)
{
	int			min_min_content;
	int			rotate_amount;
	t_psw_list	*min_min_node;
	t_psw_list	*a_list_start;

	a_list_start = *a_list;
	min_min_content = INT_MAX;
	while (*a_list != NULL)
	{
		if ((*a_list)->content < min_min_content)
		{
			min_min_content = (*a_list)->content;
			min_min_node = *a_list;
		}
		*a_list = (*a_list)->next;
	}
	*a_list = a_list_start;
	rotate_amount = calc_single_index(*a_list, min_min_node->content) - 1;
	if (rotate_amount <= (psw_lstsize(*a_list) - rotate_amount))
		run_rotate(a_list, b_list, rotate_amount, &ra);
	else
	{
		rotate_amount = psw_lstsize(*a_list) - rotate_amount;
		run_rotate(a_list, b_list, rotate_amount, &rra);
	}
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
		//if (a_list->content == 6)
		//	break;

		pb(&a_list, &b_list);
		clear_stack_values(a_list);
		clear_stack_values(b_list);

	//# wieder starten bei positionsinfo aktuallisieren bis A nur noch drei werte hat
		//printf("push:%i\n", b_list->content);
		//update_lists(a_list, b_list);
		////node_a_to_push = cheapest_node(a_list, b_list);
//update_lists(a_list, b_list);
//print_stacks(a_list, b_list);

	}

//# positionsinfo updaten und drei werte in A sortieren
	update_lists(a_list, b_list);
	sort_three(&a_list);

//#schauen welcher wert in A der nächste kleinere unter dem ersten B wert ist
//# A rotieren
//#swab B zu A
	swap_all_to_A(&a_list, &b_list);

//#A solange rotieren, bis die kleinste Zahl oben ist.
rotate_to_min(&a_list, &b_list);

//Print stacks:
//print_stacks(a_list, b_list);
//run_rotate(&a_list, &b_list, 4, &rrb);
//print_stacks(a_list, b_list);

//71 22 32 83 16 92 76 9 15 20 40 66 97 28 33 62 50 12 8 96 77 52 58 34 27 7 73 63 37 23 68 29 39 49 30 43 88 10 21 87 56 64 25 54 85 38 57 24 74 59 91 11 93 35 4 86 3 81 47 78 98 55 72 60 42 44 89 46 13 41 26 61 65 6 17 100 70 31 99 90 19 69 84 18 36 94 51 14 5 67 95 2 79 82 80 53 45 75 1 48
//Count 889. Nach opti swaptoA: 667. Nach opti rotate_to_min: 613. Nach opti rr: 573. Nach opti rrr: 513
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

		#schauen welcher wert in A der nächste kleinere unter dem ersten B wert ist
		# A rotieren
		#swab B zu A
	#A solange rotieren, bis die kleinste Zahl oben ist.
	*/


}