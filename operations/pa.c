/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:19:39 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/11 23:29:29 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_psw_list **a_list, t_psw_list **b_list)
{
	t_psw_list	*tmp;

	tmp = (*b_list)->next;
	//printf("firstA:%i firstB:%i\n", (*a_list)->content, (*b_list)->content);
	psw_lstadd_front(a_list, *b_list);
	*b_list = tmp;
	//printf("firstAafterpa:%i firstBafterpa:%i\n", (*a_list)->content, (*b_list)->content);

	write(1, "pa\n", 3);
}
