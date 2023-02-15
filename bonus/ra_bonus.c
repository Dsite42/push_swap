/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:15:48 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/15 17:42:22 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra_bonus(t_psw_list **a_list, t_psw_list **b_list)
{
	t_psw_list	*tmp;

	if (psw_lstsize(*a_list) < 2)
		error(*a_list, *b_list);
	tmp = (*a_list)->next;
	psw_lstadd_back(a_list, *a_list);
	*a_list = tmp;
}
