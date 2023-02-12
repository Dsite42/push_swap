/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:19:39 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/12 11:27:41 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_psw_list **a_list, t_psw_list **b_list)
{
	t_psw_list	*tmp;

	tmp = (*a_list)->next;
	//if (psw_lstsize(*b_list) > 0)
	//	printf("firstA:%i firstB:%i\n", (*a_list)->content, (*b_list)->content);
	psw_lstadd_front(b_list, *a_list);
	*a_list = tmp;
	//printf("firstAafterpb:%i firstBafterpb:%i\n", (*a_list)->content, (*b_list)->content);
	write(1, "pb\n", 3);
	//print_stacks(*a_list, *b_list);
}
