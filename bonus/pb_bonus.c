/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:19:39 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/15 17:42:06 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pb_bonus(t_psw_list **a_list, t_psw_list **b_list)
{
	t_psw_list	*tmp;

	if (psw_lstsize(*a_list) < 1)
		error(*a_list, *b_list);
	tmp = (*a_list)->next;
	psw_lstadd_front(b_list, *a_list);
	*a_list = tmp;
}
