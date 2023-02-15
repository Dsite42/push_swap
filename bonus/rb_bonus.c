/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:15:48 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/15 17:42:24 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rb_bonus(t_psw_list **a_list, t_psw_list **b_list)
{
	t_psw_list	*tmp;

	if (psw_lstsize(*b_list) < 2)
		error(*a_list, *b_list);
	tmp = (*b_list)->next;
	psw_lstadd_back(b_list, *b_list);
	*b_list = tmp;
}
