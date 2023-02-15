/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:19:39 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/15 17:42:03 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa_bonus(t_psw_list **a_list, t_psw_list **b_list)
{
	t_psw_list	*tmp;

	if (psw_lstsize(*b_list) < 1)
		error(*a_list, *b_list);
	tmp = (*b_list)->next;
	psw_lstadd_front(a_list, *b_list);
	*b_list = tmp;
}
